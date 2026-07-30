/*
** KORO PROJECT, 2025
** US Name Formatter
** File description:
** Prototypes of the word helpers
*/

#ifndef WORD_PRINTER_H_
    #define WORD_PRINTER_H_

char convert_to_upper(char c);
char convert_to_lower(char c);
int find_next_word(char const *str, int *start, int *end);
void put_capitalized(char const *str, int start, int end);
void put_upper(char const *str, int start, int end);

#endif /* !WORD_PRINTER_H_ */
