/*
** KORO PROJECT, 2025
** 
** File description:
** Minimal output helpers built on write only
*/

#include <unistd.h>
#include "text_to_multi_tap_output_writer.h"

int my_strlen(char const *str)
{
    int len = 0;

    while (str[len] != '\0')
        len++;
    return (len);
}

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}

void my_puterr(char const *str)
{
    write(2, str, my_strlen(str));
}
