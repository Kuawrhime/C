# clean_str

Cleans up a string: leading/trailing spaces and tabs are stripped, and any
run of spaces/tabs in the middle of the string is collapsed to a single
space.

## Usage

```
./clean_str [string]
```

With no argument, prints an empty line.

## Examples

```
$ ./clean_str "abc cba abc cab cba"
abc cba abc cab cba
$ ./clean_str " Remus and Romulus are the two mammals of Rome "
Remus and Romulus are the two mammals of Rome
$ ./clean_str "$(printf '\tHello\t\t how are you?\t ')"
Hello how are you?
$ ./clean_str
(empty line)
```

## Build and test

```
make            # build
make re          # clean rebuild
make tests_run   # Criterion unit tests (black-box)
```
