/*
** KORO PROJECT, 2025
** Scrabble Calculator
** File description:
** Computes the scrabble value of a word from a value table
*/

#include <stdlib.h>
#include <stdio.h>
#include "scrabble_calculator_output_writer.h"
#include "scrabble_calculator.h"

static void read_values(char const *arg, int *values)
{
    int i = 0;
    int letter = 0;

    while (letter < ALPHABET_SIZE) {
        values[letter] = atoi(arg + i);
        while (arg[i] != '\0' && arg[i] != ',')
            i++;
        if (arg[i] == ',')
            i++;
        letter++;
    }
}

static int get_letter_index(char c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 'a');
    if (c >= 'A' && c <= 'Z')
        return (c - 'A');
    return (-1);
}

static int compute_score(char const *word, int *values, int *score)
{
    int i = 0;
    int index;

    *score = 0;
    if (word[0] == '\0')
        return (0);
    while (word[i] != '\0') {
        index = get_letter_index(word[i]);
        if (index == -1)
            return (0);
        *score += values[index];
        i++;
    }
    return (1);
}

int main(int ac, char **av)
{
    int values[ALPHABET_SIZE];
    int score;

    if (ac != 3) {
        my_puterr("Error: invalid number of arguments.\n");
        return (84);
    }
    read_values(av[1], values);
    if (!compute_score(av[2], values, &score)) {
        my_puterr("Error: the word must only contain letters.\n");
        return (84);
    }
    printf("%d\n", score);
    return (0);
}
