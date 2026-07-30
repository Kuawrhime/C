/*
** KORO PROJECT, 2025
** Text-to-Multi-Tap
** File description:
** Translates a string into the minimal multi-tap keystrokes
*/

#include <unistd.h>
#include "text_to_multi_tap_output_writer.h"
#include "text_to_multi_tap.h"

static char const *const KEYS[KEYS_COUNT] = {
    "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

static int find_press_count(char const *letters, char c)
{
    int i = 0;

    while (letters[i] != '\0') {
        if (letters[i] == c)
            return (i + 1);
        i++;
    }
    return (0);
}

static int find_key(char c, int *presses)
{
    int key = 0;
    int presses_needed;

    while (key < KEYS_COUNT) {
        presses_needed = find_press_count(KEYS[key], c);
        if (presses_needed > 0) {
            *presses = presses_needed;
            return ('2' + key);
        }
        key++;
    }
    return (-1);
}

static void emit_group(char digit, int presses, char *last)
{
    if (*last == digit)
        write(1, " ", 1);
    while (presses > 0) {
        write(1, &digit, 1);
        presses--;
    }
    *last = digit;
}

static int emit_char(char raw, char *last)
{
    char lowered = (raw >= 'A' && raw <= 'Z') ? raw + 32 : raw;
    int presses = 1;
    int key;

    if (lowered == ' ') {
        emit_group('0', 1, last);
        return (1);
    }
    key = find_key(lowered, &presses);
    if (key == -1)
        return (0);
    if (raw >= 'A' && raw <= 'Z')
        emit_group('#', 1, last);
    emit_group((char)key, presses, last);
    return (1);
}

static int translate(char const *str)
{
    char last = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (!emit_char(str[i], &last))
            return (0);
        i++;
    }
    return (1);
}

int main(int ac, char **av)
{
    if (ac != 2) {
        my_puterr("Error: exactly one argument is required.\n");
        return (84);
    }
    if (!translate(av[1])) {
        my_puterr("Error: the string cannot be typed on a multi-tap.\n");
        return (84);
    }
    my_putstr("\n");
    return (0);
}
