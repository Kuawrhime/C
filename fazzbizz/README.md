# fazzbizz

A FizzBuzz variant over a `[start, end]` range: multiples of 3 → `Fazz`,
multiples of 5 → `Bizz`, multiples of both → `FazzBizz`, otherwise the
number itself.

## Usage

```
./fazzbizz <start> <end>
```

`start` must be ≤ `end`, otherwise exit code `84`. Exit code `84` also if
the number of arguments is not exactly 2.

## Examples

```
$ ./fazzbizz 8 12
8
Bizz
Fazz
11
12
$ ./fazzbizz 89 91
89
FazzBizz
91
$ ./fazzbizz 2 1; echo $?
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
