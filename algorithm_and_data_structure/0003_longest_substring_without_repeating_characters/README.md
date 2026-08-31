# 3. Longest Substring Without Repeating Characters

Find the length of the longest substring without repeating characters.

## Approach

Sliding window tracking, for each byte value, the index where it was last
seen. As `right` advances, if the current character was last seen inside
the current window (`last_seen[c] >= left`), jump `left` to just past
that previous occurrence — this removes the duplicate from the window in
O(1) instead of shrinking one character at a time. Track the best window
size seen. O(n) time, O(1) space (fixed 256-entry table).

## Signature

```c
int length_of_longest_substring(char const *s);
```

## Example

```
"abcabcbb" -> 3 ("abc")
"bbbbb" -> 1 ("b")
"pwwkew" -> 3 ("wke")
```

## Build and test

```
make            # compiles the object file
make tests_run   # Criterion unit tests
```
