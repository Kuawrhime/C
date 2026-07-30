/*
** KORO PROJECT, 2025
** US Name Formatter
** File description:
** Word walking and case printing helpers
*/

#include <unistd.h>
#include "word_printer.h"

char convert_to_upper(char c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

char convert_to_lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + 32);
    return (c);
}

int find_next_word(char const *str, int *start, int *end)
{
    int i = *end;

    while (str[i] == ' ' || str[i] == '\t')
        i++;
    if (str[i] == '\0')
        return (0);
    *start = i;
    while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
        i++;
    *end = i;
    return (1);
}

void put_capitalized(char const *str, int start, int end)
{
    char c;
    int first = 1;

    while (start < end) {
        c = first ? convert_to_upper(str[start]) : convert_to_lower(str[start]);
        write(1, &c, 1);
        first = 0;
        start++;
    }
}

void put_upper(char const *str, int start, int end)
{
    char c;

    while (start < end) {
        c = convert_to_upper(str[start]);
        write(1, &c, 1);
        start++;
    }
}
