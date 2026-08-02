#include <criterion/criterion.h>
#include <stdlib.h>
#include "../two_sum.h"

Test(two_sum, example1)
{
    int nums[] = {2, 7, 11, 15};
    int n;
    int *res = two_sum(nums, 4, 9, &n);

    cr_assert_eq(n, 2);
    cr_assert_eq(res[0], 0);
    cr_assert_eq(res[1], 1);
    free(res);
}

Test(two_sum, example2)
{
    int nums[] = {3, 2, 4};
    int n;
    int *res = two_sum(nums, 3, 6, &n);

    cr_assert_eq(res[0], 1);
    cr_assert_eq(res[1], 2);
    free(res);
}

Test(two_sum, duplicate_values)
{
    int nums[] = {3, 3};
    int n;
    int *res = two_sum(nums, 2, 6, &n);

    cr_assert_eq(res[0], 0);
    cr_assert_eq(res[1], 1);
    free(res);
}
