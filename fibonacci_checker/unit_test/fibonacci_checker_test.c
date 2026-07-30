/*
** KORO PROJECT, 2025
** fibonacci_checker
** File description:
** Black-box unit tests (mirrors run_tests.sh)
*/

#include <criterion/criterion.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define BIN_PATH "./fibonacci_checker"

static int run_bin(char *const argv[], char *out, size_t out_size)
{
    int pipefd[2];
    pid_t pid;
    int status;
    ssize_t n;
    size_t total = 0;

    if (pipe(pipefd) == -1)
        return (-1);
    pid = fork();
    if (pid == 0) {
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);
        close(STDERR_FILENO);
        execv(argv[0], argv);
        _exit(127);
    }
    close(pipefd[1]);
    while (total < out_size - 1) {
        n = read(pipefd[0], out + total, out_size - 1 - total);
        if (n <= 0)
            break;
        total += n;
    }
    out[total] = '\0';
    close(pipefd[0]);
    waitpid(pid, &status, 0);
    return (WIFEXITED(status) ? WEXITSTATUS(status) : -1);
}

Test(fibonacci_checker, fib1)
{
    char out[256];
    char *argv[] = {BIN_PATH, "0", "1", "1", "2", "3", "5", "8", NULL};

    run_bin(argv, out, sizeof(out));
    cr_assert_str_eq(out, "OK\n");
}

Test(fibonacci_checker, fib2)
{
    char out[256];
    char *argv[] = {
        BIN_PATH, "42", "84", "126", "210", "336", "546", "882", NULL};

    run_bin(argv, out, sizeof(out));
    cr_assert_str_eq(out, "OK\n");
}

Test(fibonacci_checker, fib3)
{
    char out[256];
    char *argv[] = {BIN_PATH, "0", "1", "1", "3", NULL};

    run_bin(argv, out, sizeof(out));
    cr_assert_str_eq(out, "Not a Fibonacci sequence\n");
}

Test(fibonacci_checker, fib4)
{
    char out[256];
    char *argv[] = {BIN_PATH, "-1", "-1", "2", NULL};

    run_bin(argv, out, sizeof(out));
    cr_assert_str_eq(out, "Not a Fibonacci sequence\n");
}

Test(fibonacci_checker, fib5)
{
    char out[256];
    char *argv[] = {BIN_PATH, "0", "1", "1", "3", NULL};
    int code = run_bin(argv, out, sizeof(out));

    cr_assert_eq(code, 1);
}

Test(fibonacci_checker, fib6)
{
    char out[256];
    char *argv[] = {BIN_PATH, "0", "1", "1", "2", "3", "5", "8", NULL};
    int code = run_bin(argv, out, sizeof(out));

    cr_assert_eq(code, 0);
}

Test(fibonacci_checker, fib7)
{
    char out[256];
    char *argv[] = {
        BIN_PATH, "4242424242", "5634118968", "9876543210", NULL};
    int code = run_bin(argv, out, sizeof(out));

    cr_assert_eq(code, 84);
}

Test(fibonacci_checker, fib8)
{
    char out[256];
    char *argv[] = {BIN_PATH, "2", "4", "6", "10", "16", "26GORILLA", NULL};
    int code = run_bin(argv, out, sizeof(out));

    cr_assert_eq(code, 84);
}

Test(fibonacci_checker, fib9)
{
    char out[256];
    char *argv[] = {BIN_PATH, NULL};
    int code = run_bin(argv, out, sizeof(out));

    cr_assert_eq(code, 84);
}
