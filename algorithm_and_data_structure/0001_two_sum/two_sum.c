/*
** KORO PROJECT, 2025
** LeetCode 1 - Two Sum
** File description:
** Open-addressing hash map from value -> index, checking the complement
** before inserting the current element
*/

#include <stdlib.h>
#include "two_sum.h"

static unsigned find_slot(int const *keys, char const *used, int cap, int key)
{
    unsigned ukey = (unsigned)key;
    unsigned pos = (ukey * 2654435761u) % (unsigned)cap;
    
    while (used[pos] && keys[pos] != key)
        pos = (pos + 1) % (unsigned) cap;
    return (pos);
}

static void release(int *keys, int *idx, char *used)
{
    free(keys);
    free(idx);
    free(used);
}

static void build_table(two_sum_ctx_t *ctx)
{
    ctx->cap = 8;
    while (ctx->cap < ctx->nums_size * 2)
        ctx->cap *= 2;
    ctx->keys = malloc(sizeof(int) * ctx->cap);
    ctx->idx = malloc(sizeof(int) * ctx->cap);
    ctx->used = calloc(ctx->cap, sizeof(char));
}

static int *make_pair(int a, int b)
{
    int *res = malloc(sizeof(int) * 2);
    if (!res) return NULL;
    res[0] = a;
    res[1] = b;
    return (res);
}

static int *search_pair(two_sum_ctx_t *ctx, int *return_size)
{
    unsigned pos;
    int i;

    for (i = 0; i < ctx->nums_size; i++) {
        pos = find_slot(ctx->keys, ctx->used, ctx->cap,
            ctx->target - ctx->nums[i]);
        if (ctx->used[pos]) {
            *return_size = 2;
            return (make_pair(ctx->idx[pos], i));
        }
        pos = find_slot(ctx->keys, ctx->used, ctx->cap, ctx->nums[i]);
        ctx->keys[pos] = ctx->nums[i];
        ctx->idx[pos] = i;
        ctx->used[pos] = 1;
    }
    *return_size = 0;
    return (NULL);
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    two_sum_ctx_t ctx;
    int *res;

    ctx.nums = nums;
    ctx.nums_size = numsSize;
    ctx.target = target;
    build_table(&ctx);
    res = search_pair(&ctx, returnSize);
    release(ctx.keys, ctx.idx, ctx.used);
    return (res);
}
