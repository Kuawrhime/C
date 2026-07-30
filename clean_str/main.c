/*
** KORO PROJECT, 2025
** Clean String
** File description:
** Prints the words of a string separated by a single space
*/

#include <unistd.h>
#include "clean_str_output_writer.h"

static int is_sep(char c)
{
    return (c == ' ' || c == '\t');
}

static void print_words(char const *str)
{
    int i = 0;
    int first = 1;
    int start;

    while (str[i] != '\0') {
        while (is_sep(str[i]))
            i++;
        if (str[i] == '\0')
            break;
        start = i;
        while (str[i] != '\0' && !is_sep(str[i]))
            i++;
        if (!first)
            write(1, " ", 1);
        write(1, str + start, i - start);
        first = 0;
    }
}

int main(int ac, char **av)
{
    if (ac > 1)
        print_words(av[1]);
    my_putstr("\n");
    return (0);
}
