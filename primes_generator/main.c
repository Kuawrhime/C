/*
** KORO PROJECT, 2025
** Primes Generator
** File description:
** Prints every prime number contained in a range
*/

#include <stdlib.h>
#include <stdio.h>
#include "primes_generator_output_writer.h"

static int is_prime(long nb)
{
    long div = 3;

    if (nb < 2)
        return (0);
    if (nb == 2)
        return (1);
    if (nb % 2 == 0)
        return (0);
    while (div * div <= nb) {
        if (nb % div == 0)
            return (0);
        div += 2;
    }
    return (1);
}

static void print_range(long start, long end)
{
    long step = (start <= end) ? 1 : -1;
    long i = start;

    while (1) {
        if (is_prime(i))
            printf("%ld\n", i);
        if (i == end)
            break;
        i += step;
    }
}

int main(int ac, char **av)
{
    if (ac != 3) {
        my_puterr("Error: invalid number of arguments.\n");
        return (84);
    }
    print_range(atoi(av[1]), atoi(av[2]));
    return (0);
}
