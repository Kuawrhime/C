# gpa_calculator

Computes a weighted GPA from a list of `grade,credits` pairs (grade from A
to E).

## Usage

```
./gpa_calculator <grade,credits> [grade,credits ...]
```

Exit code `84` if no argument is given.

## Examples

```
$ ./gpa_calculator A,3 B,2 B,9 E,5
2.37
$ ./gpa_calculator D,1 E,1000
0.00
$ ./gpa_calculator; echo $?
84
```

## Build and test

```
make            # build
make re          # clean rebuild
make tests_run   # Criterion unit tests (black-box)
```
