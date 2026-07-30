# fibonacci_checker

Checks whether a sequence of numbers passed as arguments is a valid
Fibonacci sequence (each term is the sum of the two preceding ones).

## Usage

```
./fibonacci_checker <n1> <n2> <n3> [n4 ...]
```

At least 3 numbers are required. Exit codes:
- `0` — valid sequence (`OK`)
- `1` — valid numbers but invalid sequence (`Not a Fibonacci sequence`)
- `84` — invalid arguments (not enough numbers, unparsable input, overflow)

## Examples

```
$ ./fibonacci_checker 0 1 1 2 3 5 8
OK
$ ./fibonacci_checker 0 1 1 3
Not a Fibonacci sequence
$ ./fibonacci_checker 4242424242 5634118968 9876543210; echo $?
84
$ ./fibonacci_checker; echo $?
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
