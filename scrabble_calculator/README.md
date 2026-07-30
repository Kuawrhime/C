# scrabble_calculator

Computes the Scrabble score of one or more words, given the 26 letter
values (A to Z) passed as the first argument.

## Usage

```
./scrabble_calculator "<26 comma-separated values>" <word> [word ...]
```

Returns the score of the best-scoring word. Exit code `84` if the number of
values is not 26, if a word contains a non-letter character, or if a word
is empty / no word is given.

## Examples

```
$ V="1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10"
$ ./scrabble_calculator "$V" Hugo
8
$ ./scrabble_calculator "$V" Chocolatine
18
$ ./scrabble_calculator "$V" system32; echo $?
84
```

## Note

Error messages for the `84` case are written to stderr; the subject's
worked examples redirect stderr to `/dev/null`, so only the exit code
itself is actually specified by the PDF.

## Build and test

```
make            # build
make re          # clean rebuild
make tests_run   # Criterion unit tests (black-box)
```
