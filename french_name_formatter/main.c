/*
** KORO PROJECT, 2025
** French Name Formatter
** File description:
** Pretty prints a French formatted name
*/

#include <unistd.h>
#include "french_name_formatter_output_writer.h"
#include "word_printer.h"

static void put_first_name(char const *str, int start, int end)
{
    int piece = start;

    while (piece < end) {
        while (piece < end && str[piece] != '-')
            piece++;
        put_capitalized(str, start, piece);
        if (piece < end) {
            write(1, "-", 1);
            piece++;
            start = piece;
        }
    }
}

int main(int ac, char **av)
{
    int start = 0;
    int end = 0;

    if (ac != 2) {
        my_puterr("Usage: frenchNameFormatter string\n");
        return (84);
    }
    if (!find_next_word(av[1], &start, &end))
        return (84);
    put_first_name(av[1], start, end);
    while (find_next_word(av[1], &start, &end)) {
        write(1, " ", 1);
        put_upper(av[1], start, end);
    }
    my_putstr("\n");
    return (0);
}
