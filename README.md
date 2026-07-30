# Classic C PROJECT — 13 small C exercises

This repository is a collection of 13 independent command-line programs
written in C. Each one lives in its own folder, solves one small
self-contained exercise, and can be built, run, and tested entirely on its
own — there's no shared library and no dependency between exercises.

## Repository layout

```
.
├── run_tests.sh              # builds every project, replays all 61 examples
├── anagram/
│   ├── Makefile               # all / clean / fclean / re / tests_run
│   ├── main.c                 # entry point
│   ├── <exercise>.h            # exercise-specific declarations (if any)
│   ├── <project>_output_writer.c/.h   # write()-only I/O helpers
│   ├── README.md               # this exercise's description, usage, examples
│   └── unit_test/
│       └── <project>_test.c   # Criterion tests for this exercise
├── clean_str/                 # same layout
├── fazzbizz/                  # same layout
└── ...                        # 10 more folders, same layout
```

All 13 folders follow this exact same pattern. Once you understand one,
you understand them all — the only thing that changes between folders is
the exercise logic itself. For what a specific exercise does, how to run
it, and any implementation notes specific to it, see that folder's own
`README.md` — this file only covers what's common to the whole repo.

Two naming conventions apply across every folder:
- `<project>_output_writer.c/.h` are minimal wrappers around `write()`
  (`my_putstr`, `my_puterr`, `my_strlen`), prefixed with the project name
  so that opening files by name across folders never gets ambiguous. The
  code inside is intentionally identical in every folder.

## Requirements

- `gcc` and `make`
- [Criterion](https://github.com/Snaipe/Criterion) — only needed for
  `make tests_run` inside a project folder; `run_tests.sh` and plain
  `make` don't need it.

## Quick start

```sh
# Build and smoke-test everything from the repo root:
./run_tests.sh

# Or work on a single exercise:
cd <project-folder>
make              # builds the binary
make tests_run    # builds and runs this project's Criterion tests
make fclean       # removes the binary and .o files
```

## The 13 exercises

| Folder | Binary |
|---|---|
| [`anagram/`](anagram/README.md) | `anagram` |
| [`clean_str/`](clean_str/README.md) | `clean_str` |
| [`fazzbizz/`](fazzbizz/README.md) | `fazzbizz` |
| [`fibonacci_checker/`](fibonacci_checker/README.md) | `fibonacci_checker` |
| [`french_name_formatter/`](french_name_formatter/README.md) | `frenchNameFormatter` |
| [`geek_name_formatter/`](geek_name_formatter/README.md) | `geekNameFormatter` |
| [`gpa_calculator/`](gpa_calculator/README.md) | `gpa_calculator` |
| [`primes_generator/`](primes_generator/README.md) | `primes_generator` |
| [`scrabble_calculator/`](scrabble_calculator/README.md) | `scrabble_calculator` |
| [`sort_words/`](sort_words/README.md) | `sort_words` |
| [`spongebob_case_checker/`](spongebob_case_checker/README.md) | `spongebob_case_checker` |
| [`text_to_multi_tap/`](text_to_multi_tap/README.md) | `text_to_multi_tap` |
| [`us_name_formatter/`](us_name_formatter/README.md) | `USNameFormatter` |

Build standard: `-Wall -Wextra` with zero warnings, ≤ 20 lines per
function, ≤ 5 functions per file, ≤ 80 columns per line, Epitech-style
headers.

## Testing — two independent levels

1. **`./run_tests.sh`** (repo root): rebuilds every project (`make re`) and
   replays 61 examples across all exercises, checking both stdout and the
   exit code. This is the fastest way to check "does everything still
   work" after a change anywhere in the repo.

2. **`make tests_run`** (inside a single project folder): builds that
   project's binary, compiles its Criterion suite in `unit_test/`, and
   runs it, reporting each case individually (pass/fail) instead of one
   aggregate result.

Both are self-cleaning: `run_tests.sh` only ever rebuilds via `make re`,
and `tests_run` deletes its own test binary right after running. Neither
leaves stray `.o` files or executables in the repo.
