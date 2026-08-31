/*
** KORO PROJECT, 2026
** LeetCode 3 - Longest Substring Without Repeating Characters
** File description:
**
*/

#include "longest_substring_without_repeating_characters.h"

int length_of_longest_substring(char const *s)
{
    int last_seen[256];
    int left = 0;
    int best = 0;
    unsigned char c;
    int i;
    int right;

    for (i = 0; i < 256; i++)
        last_seen[i] = -1;
    for (right = 0; s[right] != '\0'; right++) {
        c = (unsigned char)s[right];
        if (last_seen[c] >= left)
            left = last_seen[c] + 1;
        last_seen[c] = right;
        if (right - left + 1 > best)
            best = right - left + 1;
    }
    return (best);
}
