# french_name_formatter

Formats a full name the French way: first name(s) capitalized after each
hyphen, last name fully uppercase.

Binary: `frenchNameFormatter` (name required by the subject, different from
the folder name).

## Usage

```
./frenchNameFormatter "<firstname lastname>"
```

Exit code `84` if no argument is given.

## Examples

```
$ ./frenchNameFormatter "JeAN-MICHEL don diEgo De la vega"
Jean-Michel DON DIEGO DE LA VEGA
$ ./frenchNameFormatter; echo $?
84
```

## Build and test

```
make            # build -> ./frenchNameFormatter
make re          # clean rebuild
make tests_run   # Criterion unit tests (black-box)
```
