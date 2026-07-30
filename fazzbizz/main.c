/*
** KORO PROJECT, 2025
** FazzBizz
** File description:
** Prints a range of numbers following the FazzBizz rules
*/

#include <stdlib.h>
#include <stdio.h>
#include "fazzbizz_output_writer.h"

static void print_value(int nb)
{
    if (nb % 9 == 0 && nb % 10 == 0)
        printf("FazzBizz\n");
    else if (nb % 10 == 0)
        printf("Fazz\n");
    else if (nb % 9 == 0)
        printf("Bizz\n");
    else
        printf("%d\n", nb);
}

int main(int ac, char **av)
{
    int start;
    int end;

    if (ac != 3) {
        my_puterr("Error: invalid number of arguments.\n");
        return (84);
    }
    start = atoi(av[1]);
    end = atoi(av[2]);
    if (end < start) {
        my_puterr("Error: the second parameter must be greater than the ");
        my_puterr("first one.\n");
        return (84);
    }
    while (start <= end) {
        print_value(start);
        start++;
    }
    return (0);
}
