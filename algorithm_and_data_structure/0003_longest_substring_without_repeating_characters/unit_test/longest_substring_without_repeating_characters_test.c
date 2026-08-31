#include <criterion/criterion.h>
#include "../longest_substring_without_repeating_characters.h"

Test(longest_substring_without_repeating_characters, example1)
{
    cr_assert_eq(length_of_longest_substring("abcabcbb"), 3);
}

Test(longest_substring_without_repeating_characters, all_same)
{
    cr_assert_eq(length_of_longest_substring("bbbbb"), 1);
}

Test(longest_substring_without_repeating_characters, example3)
{
    cr_assert_eq(length_of_longest_substring("pwwkew"), 3);
}

Test(longest_substring_without_repeating_characters, empty_string)
{
    cr_assert_eq(length_of_longest_substring(""), 0);
}
