/*
** LeetCode 1 - Two Sum
** File description:
** Open-addressing hash map from value -> index, checking the complement
** before inserting the current element
*/

#include <stdlib.h>
#include "two_sum.h"

static unsigned find_slot(int const *keys, char const *used, int cap,
    int key)
{
    unsigned pos = ((unsigned)key * 2654435761u) % (unsigned)cap;

    while (used[pos] && keys[pos] != key)
        pos = (pos + 1) % (unsigned)cap;
    return (pos);
}

static void release(int *keys, int *idx, char *used)
{
    free(keys);
    free(idx);
    free(used);
}

int *two_sum(int const *nums, int nums_size, int target, int *return_size)
{
    int cap = 8;
    int *keys;
    int *idx;
    char *used;
    unsigned pos;
    int *res;
    int i;

    while (cap < nums_size * 2)
        cap *= 2;
    keys = malloc(sizeof(int) * cap);
    idx = malloc(sizeof(int) * cap);
    used = calloc(cap, sizeof(char));
    for (i = 0; i < nums_size; i++) {
        pos = find_slot(keys, used, cap, target - nums[i]);
        if (used[pos]) {
            res = malloc(sizeof(int) * 2);
            res[0] = idx[pos];
            res[1] = i;
            *return_size = 2;
            release(keys, idx, used);
            return (res);
        }
        pos = find_slot(keys, used, cap, nums[i]);
        keys[pos] = nums[i];
        idx[pos] = i;
        used[pos] = 1;
    }
    *return_size = 0;
    release(keys, idx, used);
    return (NULL);
}
