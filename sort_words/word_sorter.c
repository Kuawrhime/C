/*
** KORO PROJECT, 2025
** Sort Words
** File description:
** Word splitting and stable alphabetical sorting
*/

#include "word_sorter.h"

int count_words(char const *str)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '\0') {
        while (is_sep(str[i]))
            i++;
        if (str[i] == '\0')
            break;
        nb++;
        while (str[i] != '\0' && !is_sep(str[i]))
            i++;
    }
    return (nb);
}

void split_words(char const *str, word_t *words)
{
    int i = 0;
    int nb = 0;
    int start;

    while (str[i] != '\0') {
        while (is_sep(str[i]))
            i++;
        if (str[i] == '\0')
            break;
        start = i;
        while (str[i] != '\0' && !is_sep(str[i]))
            i++;
        words[nb].start = start;
        words[nb].len = i - start;
        nb++;
    }
}

static int compare_words(char const *str, word_t const *a, word_t const *b)
{
    int i = 0;
    char ca;
    char cb;

    while (i < a->len && i < b->len) {
        ca = convert_to_lower(str[a->start + i]);
        cb = convert_to_lower(str[b->start + i]);
        if (ca != cb)
            return (ca - cb);
        i++;
    }
    return (a->len - b->len);
}

void sort_words(char const *str, word_t *words, int nb)
{
    int i = 1;
    int j;
    word_t key;

    while (i < nb) {
        key = words[i];
        j = i - 1;
        while (j >= 0 && compare_words(str, &words[j], &key) > 0) {
            words[j + 1] = words[j];
            j--;
        }
        words[j + 1] = key;
        i++;
    }
}
