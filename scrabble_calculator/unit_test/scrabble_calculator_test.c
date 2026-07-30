/*
** KORO PROJECT, 2025
** scrabble_calculator
** File description:
** Black-box unit tests (mirrors run_tests.sh)
*/

#include <criterion/criterion.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define BIN_PATH "./scrabble_calculator"
#define VALUES "1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10"

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

Test(scrabble_calculator, scrab1)
{
    char out[256];
    char *argv[] = {BIN_PATH, VALUES, "Hugo", NULL};

    run_bin(argv, out, sizeof(out));
    cr_assert_str_eq(out, "8\n");
}

Test(scrabble_calculator, scrab2)
{
    char out[256];
    char *argv[] = {BIN_PATH, VALUES, "Chocolatine", NULL};

    run_bin(argv, out, sizeof(out));
    cr_assert_str_eq(out, "18\n");
}

Test(scrabble_calculator, scrab3)
{
    char out[256];
    char *argv[] = {BIN_PATH, VALUES, "system32", NULL};
    int code = run_bin(argv, out, sizeof(out));

    cr_assert_eq(code, 84);
}

Test(scrabble_calculator, scrab4)
{
    char out[256];
    char *argv[] = {BIN_PATH, VALUES, "", NULL};
    int code = run_bin(argv, out, sizeof(out));

    cr_assert_eq(code, 84);
}

Test(scrabble_calculator, scrab5)
{
    char out[256];
    char *argv[] = {BIN_PATH, NULL};
    int code = run_bin(argv, out, sizeof(out));

    cr_assert_eq(code, 84);
}
