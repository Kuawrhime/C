/*
** KORO PROJECT, 2025
** text_to_multi_tap
** File description:
** Black-box unit tests (mirrors run_tests.sh)
*/

#include <criterion/criterion.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define BIN_PATH "./text_to_multi_tap"

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

Test(text_to_multi_tap, mt1)
{
    char out[256];
    char *argv[] = {BIN_PATH, "cafe", NULL};

    run_bin(argv, out, sizeof(out));
    cr_assert_str_eq(out, "222 2333 33\n");
}

Test(text_to_multi_tap, mt2)
{
    char out[256];
    char *argv[] = {BIN_PATH, "Chocolatine", NULL};

    run_bin(argv, out, sizeof(out));
    cr_assert_str_eq(out, "#22244666222666555284446633\n");
}

Test(text_to_multi_tap, mt3)
{
    char out[256];
    char *argv[] = {BIN_PATH, "Hello World", NULL};

    run_bin(argv, out, sizeof(out));
    cr_assert_str_eq(out, "#4433555 5556660#96667775553\n");
}

Test(text_to_multi_tap, mt4)
{
    char out[256];
    char *argv[] = {BIN_PATH, "AAAH", NULL};

    run_bin(argv, out, sizeof(out));
    cr_assert_str_eq(out, "#2#2#2#44\n");
}

Test(text_to_multi_tap, mt5)
{
    char out[256];
    char *argv[] = {BIN_PATH, "", NULL};

    run_bin(argv, out, sizeof(out));
    cr_assert_str_eq(out, "\n");
}

Test(text_to_multi_tap, mt6)
{
    char out[256];
    char *argv[] = {BIN_PATH, "", NULL};
    int code = run_bin(argv, out, sizeof(out));

    cr_assert_eq(code, 0);
}

Test(text_to_multi_tap, mt7)
{
    char out[256];
    char *argv[] = {BIN_PATH, "pain au choc****", NULL};
    int code = run_bin(argv, out, sizeof(out));

    cr_assert_eq(code, 84);
}
