/*
** KORO PROJECT, 2025
** Spongebob Case Checker
** File description:
** Checks that a string is written in the Spongebob case
*/

#include "spongebob_case_checker_output_writer.h"
#include "spongebob_case_checker.h"

static int get_letter_case(char c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    if (c >= 'A' && c <= 'Z')
        return (2);
    return (0);
}

static int is_spongebob(char const *str)
{
    int i = 0;
    int last = 0;
    int run = 0;
    int current;

    while (str[i] != '\0') {
        current = get_letter_case(str[i]);
        i++;
        if (current == 0)
            continue;
        run = (current == last) ? run + 1 : 1;
        if (run > MAX_SAME_CASE_RUN)
            return (0);
        last = current;
    }
    return (1);
}

int main(int ac, char **av)
{
    if (ac != 2) {
        my_puterr("Error: exactly one argument is required.\n");
        return (84);
    }
    if (is_spongebob(av[1]))
        my_putstr("OK\n");
    else
        my_putstr("Invalid\n");
    return (0);
}
