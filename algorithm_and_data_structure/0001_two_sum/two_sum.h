/*
** KORO PROJECT, 2025
** LeetCode 1 - Two Sum
** File description:
** two_sum declarations
*/

#ifndef TWO_SUM_H_
    #define TWO_SUM_H_

int *two_sum(int const *nums, int nums_size, int target, int *return_size);

typedef struct two_sum_ctx_s {
    int const *nums;
    int nums_size;
    int target;
    int cap;
    int *keys;
    int *idx;
    char *used;
} two_sum_ctx_t;

#endif /* !TWO_SUM_H_ */
