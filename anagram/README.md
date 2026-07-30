# anagram

Checks whether two strings are anagrams of each other: case is ignored, but
**every** character counts, spaces included.

## Usage

```
./anagram <string1> <string2>
```

Exit code `84` if the number of arguments is not exactly 2.

## Examples

```
$ ./anagram "Rail Safety" "Fairy tales"
anagram!
$ ./anagram moo moon
no anagrams.
$ ./anagram foobar; echo $?
84
```

## Note

Comparison is done on *all* characters, spaces included (the subject says
"rearranging all the characters"). To ignore spaces instead, filter them
out in `fill_count()`. Two identical strings are considered anagrams of
each other.

## Build and test

```
make            # build
make re          # clean rebuild
make tests_run   # Criterion unit tests (black-box)
```
