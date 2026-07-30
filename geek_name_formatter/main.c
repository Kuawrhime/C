/*
** KORO PROJECT, 2025
** Geek Name Formatter
** File description:
** Pretty prints a name in apply_leet speak with alternating case
*/

#include <unistd.h>
#include "geek_name_formatter_output_writer.h"

static char apply_case(char c, int index)
{
    if (index % 2 == 0 && c >= 'a' && c <= 'z')
        return (c - 32);
    if (index % 2 == 1 && c >= 'A' && c <= 'Z')
        return (c + 32);
    return (c);
}

static char apply_leet(char c)
{
    char const *from = "oOiIuUeEaAyY";
    char const *to = "001122334455";
    int i = 0;

    while (from[i] != '\0') {
        if (c == from[i])
            return (to[i]);
        i++;
    }
    return (c);
}

static void put_word(char const *str, int start, int end)
{
    char c;
    int index = 0;

    while (start < end) {
        c = apply_leet(apply_case(str[start], index));
        write(1, &c, 1);
        index++;
        start++;
    }
    write(1, " ", 1);
}

static int find_next_word(char const *str, int *start, int *end)
{
    int i = *end;

    while (str[i] == ' ')
        i++;
    if (str[i] == '\0')
        return (0);
    *start = i;
    while (str[i] != '\0' && str[i] != ' ')
        i++;
    *end = i;
    return (1);
}

int main(int ac, char **av)
{
    int start = 0;
    int end = 0;

    if (ac != 2) {
        my_puterr("Usage: geekNameFormatter string\n");
        return (84);
    }
    while (find_next_word(av[1], &start, &end))
        put_word(av[1], start, end);
    my_putstr("\n");
    return (0);
}
