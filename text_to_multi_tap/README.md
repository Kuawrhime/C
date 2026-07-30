# text_to_multi_tap

Converts text into the key sequence you'd type on an old phone keypad
(multi-tap input): each letter is a run of digit presses on its key, `#` is
used to wait/separate when the same key must be pressed again in a row.

## Usage

```
./text_to_multi_tap [text]
```

Exit code `84` if the text contains a character with no key mapping. Exit
code `0` on success, including with an empty string.

## Examples

```
$ ./text_to_multi_tap cafe
222 2333 33
$ ./text_to_multi_tap Chocolatine
#22244666222666555284446633
$ ./text_to_multi_tap AAAH
#2#2#2#44
$ ./text_to_multi_tap ""
(empty line), exit 0
$ ./text_to_multi_tap "pain au choc****"; echo $?
84
```

## Note

The wait (rendered as a space) is only inserted when the key to press is
the same as the **last key pressed** — `#` and `0` both count as
keypresses, so they reset the wait (see `AAAH` → `#2#2#2#44`).

## Build and test

```
make            # build
make re          # clean rebuild
make tests_run   # Criterion unit tests (black-box)
```
