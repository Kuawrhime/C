/*
** KORO PROJECT, 2025
** gpa_calculator
** File description:
** Black-box unit tests (mirrors run_tests.sh)
*/

#include <criterion/criterion.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define BIN_PATH "./gpa_calculator"

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

Test(gpa_calculator, gpa1)
{
    char out[256];
    char *argv[] = {BIN_PATH, "A,3", "B,2", "B,9", "E,5", NULL};

    run_bin(argv, out, sizeof(out));
    cr_assert_str_eq(out, "2.37\n");
}

Test(gpa_calculator, gpa2)
{
    char out[256];
    char *argv[] = {BIN_PATH, "D,20", "B,1", "C,2", NULL};

    run_bin(argv, out, sizeof(out));
    cr_assert_str_eq(out, "1.17\n");
}

Test(gpa_calculator, gpa3)
{
    char out[256];
    char *argv[] = {BIN_PATH, "A,6", "E,6", NULL};

    run_bin(argv, out, sizeof(out));
    cr_assert_str_eq(out, "2.00\n");
}

Test(gpa_calculator, gpa4)
{
    char out[256];
    char *argv[] = {BIN_PATH, "D,1", "E,1000", NULL};

    run_bin(argv, out, sizeof(out));
    cr_assert_str_eq(out, "0.00\n");
}

Test(gpa_calculator, gpa5)
{
    char out[256];
    char *argv[] = {BIN_PATH, NULL};
    int code = run_bin(argv, out, sizeof(out));

    cr_assert_eq(code, 84);
}
