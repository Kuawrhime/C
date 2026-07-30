/*
** KORO PROJECT, 2025
** Sort Words
** File description:
** Prints the words of a string in alphabetical order
*/

#include <unistd.h>
#include <stdlib.h>
#include "sort_words_output_writer.h"
#include "word_sorter.h"

static void print_words(char const *str, word_t *words, int nb)
{
    int i = 0;

    while (i < nb) {
        if (i > 0)
            write(1, " ", 1);
        write(1, str + words[i].start, words[i].len);
        i++;
    }
}

static int run(char const *str)
{
    int nb = count_words(str);
    word_t *words;

    if (nb == 0)
        return (0);
    words = malloc(sizeof(word_t) * nb);
    if (words == NULL)
        return (84);
    split_words(str, words);
    sort_words(str, words, nb);
    print_words(str, words, nb);
    free(words);
    return (0);
}

int main(int ac, char **av)
{
    int status = 0;

    if (ac > 1)
        status = run(av[1]);
    if (status != 0)
        return (status);
    my_putstr("\n");
    return (0);
}
