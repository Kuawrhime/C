/*
** KORO PROJECT, 2025
** US Name Formatter
** File description:
** Pretty prints a US formatted name
*/

#include <unistd.h>
#include "us_name_formatter_output_writer.h"
#include "word_printer.h"

static void put_first_name(char const *str, int start, int end)
{
    if (end - start == 2) {
        put_upper(str, start, end);
        return;
    }
    put_capitalized(str, start, end);
}

static void put_middle(char const *str, int start)
{
    char c = convert_to_upper(str[start]);

    write(1, &c, 1);
    write(1, ".", 1);
}

static void put_last_name(char const *str, int start, int end)
{
    put_capitalized(str, start, end);
    while (find_next_word(str, &start, &end)) {
        write(1, " ", 1);
        put_capitalized(str, start, end);
    }
}

static int put_rest(char const *str, int *start, int *end)
{
    write(1, " ", 1);
    if (*end - *start == 1) {
        put_middle(str, *start);
        if (!find_next_word(str, start, end))
            return (0);
        write(1, " ", 1);
    }
    put_last_name(str, *start, *end);
    return (0);
}

int main(int ac, char **av)
{
    int start = 0;
    int end = 0;

    if (ac != 2) {
        my_puterr("Usage: USNameFormatter string\n");
        return (84);
    }
    if (!find_next_word(av[1], &start, &end))
        return (84);
    put_first_name(av[1], start, end);
    if (find_next_word(av[1], &start, &end))
        put_rest(av[1], &start, &end);
    my_putstr("\n");
    return (0);
}
