/*
** KORO PROJECT, 2025
** Sort Words
** File description:
** Prototypes of the word splitting and sorting helpers
*/

#ifndef WORD_SORTER_H_
    #define WORD_SORTER_H_

typedef struct word_s
{
    int start;
    int len;
} word_t;

int is_sep(char c);
char convert_to_lower(char c);
int count_words(char const *str);
void split_words(char const *str, word_t *words);
void sort_words(char const *str, word_t *words, int nb);

#endif /* !WORD_SORTER_H_ */
