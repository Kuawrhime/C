/*
** KORO PROJECT, 2025
** clean_str
** File description:
** Black-box unit tests (mirrors run_tests.sh)
*/

#include <criterion/criterion.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define BIN_PATH "./clean_str"

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

Test(clean_str, clean1)
{
    char out[256];
    char *argv[] = {BIN_PATH, "abc cba abc cab cba", NULL};

    run_bin(argv, out, sizeof(out));
    cr_assert_str_eq(out, "abc cba abc cab cba\n");
}

Test(clean_str, clean2)
{
    char out[256];
    char *argv[] = {BIN_PATH,
        " Remus and Romulus are the two mammals of Rome ", NULL};

    run_bin(argv, out, sizeof(out));
    cr_assert_str_eq(out, "Remus and Romulus are the two mammals of Rome\n");
}

Test(clean_str, clean3)
{
    char out[256];
    char *argv[] = {BIN_PATH, "\tHello\t\t how are you?\t ", NULL};

    run_bin(argv, out, sizeof(out));
    cr_assert_str_eq(out, "Hello how are you?\n");
}

Test(clean_str, clean4)
{
    char out[256];
    char *argv[] = {BIN_PATH, NULL};

    run_bin(argv, out, sizeof(out));
    cr_assert_str_eq(out, "\n");
}
