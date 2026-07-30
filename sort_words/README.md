# sort_words

Sorts the words of a string alphabetically, case-insensitive, stable sort
(the shorter word comes first on a common prefix; on a strict tie, original
order is kept — `A` before `a`).

## Usage

```
./sort_words [string]
```

With no argument, prints an empty line.

## Examples

```
$ ./sort_words "A a b B cc ca cd"
A a b B ca cc cd
$ ./sort_words "somewhere i     lost just my sanity"
i just lost my sanity somewhere
$ ./sort_words
(empty line)
```

## Note

Sort is stable and case-insensitive; on a common prefix the shorter word
sorts first (`ca` < `cc` < `cd`); on a strict tie, original order is
preserved (`A` sorts before `a`).

## Build and test

```
make            # build
make re          # clean rebuild
make tests_run   # Criterion unit tests (black-box)
```
