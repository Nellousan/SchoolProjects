/*
** EPITECH PROJECT, 2020
** shell unsetenv
** File description:
** a
*/

#include <stdlib.h>
#include "minishell.h"
#include "my.h"
#include "a_malloc.h"

int shell_unsetenv(shell_t *shell, char **cmd)
{
    int i = 0;
    if (my_array_size(cmd) < 2) {
        my_printf("unsetenv: Too few arguments.\n");
        return 1;
    }
    i = env_checkvar(ENVP, cmd[1]);
    if (i == -1)
        return 0;
    ENVP[i][0] = '\0';
    return 0;
}
