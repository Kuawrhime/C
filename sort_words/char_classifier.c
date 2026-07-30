/*
** KORO PROJECT, 2025
** Sort Words
** File description:
** Character classification helpers
*/

#include "word_sorter.h"

int is_sep(char c)
{
    return (c == ' ' || c == '\t');
}

char convert_to_lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + 32);
    return (c);
}
