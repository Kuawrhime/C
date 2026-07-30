/*
** KORO PROJECT, 2025
** GPA Calculator
** File description:
** Computes a weighted grade point average
*/

#include <stdlib.h>
#include <stdio.h>
#include "gpa_calculator_output_writer.h"

static int get_grade_points(char grade)
{
    if (grade == 'A')
        return (4);
    if (grade == 'B')
        return (3);
    if (grade == 'C')
        return (2);
    if (grade == 'D')
        return (1);
    return (0);
}

static int get_credits(char const *arg)
{
    int i = 0;

    while (arg[i] != '\0' && arg[i] != ',')
        i++;
    if (arg[i] == '\0')
        return (0);
    return (atoi(arg + i + 1));
}

static long accumulate(int ac, char **av, long *total_credits)
{
    int i = 1;
    long total_points = 0;
    int credits;

    while (i < ac) {
        credits = get_credits(av[i]);
        total_points += (long)get_grade_points(av[i][0]) * credits;
        *total_credits += credits;
        i++;
    }
    return (total_points);
}

int main(int ac, char **av)
{
    long total_points;
    long total_credits = 0;

    if (ac < 2) {
        my_puterr("Error: at least one grade is required.\n");
        return (84);
    }
    total_points = accumulate(ac, av, &total_credits);
    if (total_credits == 0) {
        my_puterr("Error: the total credits cannot be zero.\n");
        return (84);
    }
    printf("%.2f\n", (double)total_points / (double)total_credits);
    return (0);
}
