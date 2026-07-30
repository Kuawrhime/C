/*
** KORO PROJECT, 2025
** Fibonacci Checker
** File description:
** Checks whether the given list of integers is a Fibonacci sequence
*/

#include <limits.h>
#include "fibonacci_checker_output_writer.h"
#include "fibonacci_checker.h"

static int parse_int(char const *str, long long *dest)
{
    int i = 0;
    int sign = 1;
    long long value = 0;

    if (str[0] == '-' || str[0] == '+') {
        sign = (str[0] == '-') ? -1 : 1;
        i++;
    }
    if (str[i] == '\0')
        return (0);
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        value = value * 10 + (str[i] - '0');
        if (value * sign > INT_MAX || value * sign < INT_MIN)
            return (0);
        i++;
    }
    *dest = value * sign;
    return (1);
}

static int read_numbers(int ac, char **av, long long *nums)
{
    int i = 1;

    while (i < ac) {
        if (!parse_int(av[i], &nums[i - 1]))
            return (0);
        i++;
    }
    return (1);
}

static int is_fibonacci(long long *nums, int len)
{
    int i = 2;

    while (i < len) {
        if (nums[i] != nums[i - 1] + nums[i - 2])
            return (0);
        i++;
    }
    return (1);
}

int main(int ac, char **av)
{
    long long nums[MAX_NUMBERS];

    if (ac < 4 || ac > MAX_NUMBERS + 1) {
        my_puterr("Error: invalid arguments.\n");
        return (84);
    }
    if (!read_numbers(ac, av, nums)) {
        my_puterr("Error: invalid arguments.\n");
        return (84);
    }
    if (is_fibonacci(nums, ac - 1)) {
        my_putstr("OK\n");
        return (0);
    }
    my_putstr("Not a Fibonacci sequence\n");
    return (1);
}
