# spongebob_case_checker

Checks whether a string follows "SpongeBob mocking case": letter case must
alternate (upper/lower), non-letter characters don't count toward the
alternation.

## Usage

```
./spongebob_case_checker <string>
```

Prints `OK` or `Invalid`. Exit code `84` if no argument is given (an empty
string is a valid argument).

## Examples

```
$ ./spongebob_case_checker " wHY dO YoU CRaSh? "
OK
$ ./spongebob_case_checker "WELCOME MR. KRABS"
Invalid
$ ./spongebob_case_checker ""
OK
$ ./spongebob_case_checker; echo $?
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
