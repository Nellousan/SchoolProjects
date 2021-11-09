/*
** EPITECH PROJECT, 2020
** shell load
** File description:
** a
*/

#include "minishell.h"
#include "a_malloc.h"

shell_t *shell_load(char **envp)
{
    shell_t *shell = a_malloc(sizeof(shell_t) | A_LIST(1));
    ENV = env_load(envp);
    CMD = cmd_load();
    PATH = path_load(ENVP);
    EXIT = 0;
    return shell;
}
