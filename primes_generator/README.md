# primes_generator

Lists the prime numbers between two bounds, in the order determined by the
arguments (if `start > end`, the list is descending).

## Usage

```
./primes_generator <start> <end>
```

Exit code `84` if the number of arguments is not exactly 2.

## Examples

```
$ ./primes_generator 2 5
2
3
5
$ ./primes_generator 10 1
7
5
3
2
$ ./primes_generator 90 95
(no output, no prime in range)
$ ./primes_generator; echo $?
84
```

## Build and test

```
make            # build
make re          # clean rebuild
make tests_run   # Criterion unit tests (black-box)
```
