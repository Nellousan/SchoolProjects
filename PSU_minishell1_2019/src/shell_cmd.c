/*
** EPITECH PROJECT, 2020
** shell cmd
** File description:
** a
*/

#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"
#include "my.h"
#include "a_malloc.h"

int shell_cmd(shell_t *shell, char **cmd)
{
    int done = 0;
    for (int i = 0; CMD[i] != NULL; i++)
        if (!my_strcmp(cmd[0], CMD[i]->cmd)) {
            CMD[i]->fptr(shell, cmd);
            done = 1;
        }
    if (!done)
        done = shell_exec(shell, cmd);
    if (!done)
        my_printf("%s: Command not found.\n", cmd[0]);
    return 0;
}
