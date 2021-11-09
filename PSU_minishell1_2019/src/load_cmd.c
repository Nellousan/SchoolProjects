/*
** EPITECH PROJECT, 2020
** load cmd
** File description:
** a
*/

#include <stdlib.h>
#include "minishell.h"
#include "my.h"
#include "a_malloc.h"

cmd_t *cmd_init(char *cmd_name, int (*fptr)(shell_t *shell, char **cmd))
{
    cmd_t *cmd = a_malloc(sizeof(cmd_t) | A_LIST(1));
    cmd->cmd = my_astrdup(cmd_name, 1);
    cmd->fptr = fptr;
    return cmd;
}

cmd_t **cmd_load(void)
{
    cmd_t **cmd = a_malloc(sizeof(cmd_t *) * 6 | A_LIST(1));
    cmd[0] = cmd_init("exit", &shell_exit);
    cmd[1] = cmd_init("env", &shell_env);
    cmd[2] = cmd_init("setenv", &shell_setenv);
    cmd[3] = cmd_init("unsetenv", &shell_unsetenv);
    cmd[4] = cmd_init("cd", &shell_cd);
    cmd[5] = NULL;
    return cmd;
}
