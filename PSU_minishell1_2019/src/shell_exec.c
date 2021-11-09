/*
** EPITECH PROJECT, 2020
** shell exec
** File description:
** a
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include "minishell.h"
#include "my.h"

int shell_exec_exit_status(shell_t *shell, int status)
{
    char *strerr;
    EXIT = WEXITSTATUS(status);
    if (!status)
        return 0;
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == SIGFPE)
            write(2, SIGFPEMSG, my_strlen(SIGFPEMSG));
        else {
            strerr = strsignal(WTERMSIG(status));
            write(2, strerr, my_strlen(strerr));
            my_printf((WCOREDUMP(status)) ? " (core dumped)\n" : "\n");
        }
    }
    return 0;
}

int shell_exec_exec(shell_t *shell, char **cmd, char *path_cat)
{
    int status = 0;
    pid_t child_pid = fork();
    if (!child_pid) {
        status = execve(path_cat, cmd, ENVP);
        if (status) {
            my_printf("%s: %s.%s\n", cmd[0], strerror(errno),
            (errno == ENOEXEC) ? " Wrong Architecture." : "");
            exit(84);
        }
    }
    waitpid(child_pid, &status, 0);
    shell_exec_exit_status(shell, status);
    return 0;
}

int shell_exec(shell_t *shell, char **cmd)
{
    int done = 0;
    int access_status;
    char *path_cat;
    for (int i = 0; PATH[i] != NULL && done == 0; i++) {
        path_cat = shell_strcat(PATH[i], "/");
        path_cat = shell_strcat(path_cat, cmd[0]);
        access_status = access(path_cat, X_OK);
        if (!access_status) {
            shell_exec_exec(shell, cmd, path_cat);
            done = 1;
        }
    } if (!done) {
        access_status = access(cmd[0], X_OK);
        if (!access_status) {
            shell_exec_exec(shell, cmd, cmd[0]);
            done = 1;
        }
    }
    return done;
}
