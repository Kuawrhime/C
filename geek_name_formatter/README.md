# geek_name_formatter

Turns a name into "leet speak": alternating case plus substitution of
certain letters with digits (a→4, e→3, i→1, o→0, ...).

Binary: `geekNameFormatter` (name required by the subject, different from
the folder name).

## Usage

```
./geekNameFormatter "<name>"
```

Exit code `84` if no argument is given.

## Examples

```
$ ./geekNameFormatter 'santa Tomato!KETCHUP/'
S4Nt4 T0M4T0!k3tCh2p/ 
$ ./geekNameFormatter; echo $?
84
```

## Note

There's a trailing space after the last word (`S4Nt4 T0M4T0!k3tCh2p/ `,
space before the newline) — this matches the subject's expected output
exactly. If that space turns out to be a formatting artifact in the
subject PDF rather than intended, remove the trailing `write(1, " ", 1);`
in `put_word()` and handle the separator between words differently.

## Build and test

```
make            # build -> ./geekNameFormatter
make re          # clean rebuild
make tests_run   # Criterion unit tests (black-box)
```
