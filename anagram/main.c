/*
** KORO PROJECT, 2025
** Anagram
** File description:
** Tells whether two strings are anagrams of one another
*/

#include "anagram_output_writer.h"
#include "anagram.h"

static char convert_to_lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + 32);
    return (c);
}

static void fill_count(int *count, char const *str, int sign)
{
    int i = 0;

    while (str[i] != '\0') {
        count[(unsigned char)convert_to_lower(str[i])] += sign;
        i++;
    }
}

static int is_anagram(char const *first, char const *second)
{
    int count[ASCII_TABLE_SIZE] = {0};
    int i = 0;

    fill_count(count, first, 1);
    fill_count(count, second, -1);
    while (i < ASCII_TABLE_SIZE) {
        if (count[i] != 0)
            return (0);
        i++;
    }
    return (1);
}

int main(int ac, char **av)
{
    if (ac < 3) {
        my_puterr("Error: not enough arguments.\n");
        return (84);
    }
    if (ac > 3) {
        my_puterr("Error: too many arguments.\n");
        return (84);
    }
    if (is_anagram(av[1], av[2]))
        my_putstr("anagram!\n");
    else
        my_putstr("no anagrams.\n");
    return (0);
}
