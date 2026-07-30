# us_name_formatter

Formats a name the US way: first name capitalized, optional middle name
reduced to an initial followed by a period, last name capitalized.

Binary: `USNameFormatter` (name required by the subject, different from the
folder name).

## Usage

```
./USNameFormatter "<name>"
```

Exit code `84` if no argument is given.

## Examples

```
$ ./USNameFormatter "pJ HARVEY"
PJ Harvey
$ ./USNameFormatter "MiCkAeL j FoX"
Mickael J. Fox
$ ./USNameFormatter; echo $?
84
```

## Build and test

```
make            # build -> ./USNameFormatter
make re          # clean rebuild
make tests_run   # Criterion unit tests (black-box)
```
