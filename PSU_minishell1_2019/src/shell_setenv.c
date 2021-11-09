/*
** EPITECH PROJECT, 2020
** shell setenv
** File description:
** a
*/

#include <stdlib.h>
#include "minishell.h"
#include "my.h"
#include "a_malloc.h"

int shell_envrealloc(shell_t *shell)
{
    char **newenv = malloc(sizeof(char *) * (my_array_size(ENVP) + 2));
    int i = 0;
    for (i = 0; ENVP[i] != NULL; i++)
        newenv[i] = ENVP[i];
    newenv[i] = NULL;
    newenv[i + 1] = NULL;
    free(ENVP);
    ENVP = newenv;
    return 0;
}

int shell_setenv_add(shell_t *shell, char **cmd)
{
    int i = 0;
    shell_envrealloc(shell);
    for (i = 0; ENVP[i] != NULL; i++);
    ENVP[i] = my_astrdup(shell_strcat(cmd[1], "="), 1);
    if (cmd[2] == NULL)
        return 3;
    ENVP[i] = my_astrdup(shell_strcat(ENVP[i], cmd[2]), 1);
    return 0;
}

int shell_setenv_change(shell_t *shell, char **cmd)
{
    int j = 0;
    int i = env_checkvar(ENVP, cmd[1]);
    if (i == -1)
        return 0;
    for (j = 0; ENVP[i][j] != '='; j++);
    ENVP[i][j + 1] = '\0';
    if (cmd[2] != NULL)
        ENVP[i] = my_astrdup(shell_strcat(ENVP[i], cmd[2]), 1);
    return 1;
}

int shell_setenv_validity_check(char **cmd)
{
    char c = cmd[1][0];
    if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z')) {
        my_printf("setenv: Variable name must begin with a letter.\n");
        return 0;
    }
    if (!is_alphanum(cmd[1])) {
        my_printf("%s%s\n", "setenv: Variable name must",
        " contain alphanumeric characters.");
        return 0;
    }
    return 1;
}

int shell_setenv(shell_t *shell, char **cmd)
{
    if (my_array_size(cmd) == 1) {
        shell_env(shell, cmd);
        return 1;
    } else if (my_array_size(cmd) > 3) {
        my_printf("setenv: Too many arguments.\n");
        return 2;
    }
    if (!shell_setenv_validity_check(cmd))
        return 3;
    if (!shell_setenv_change(shell, cmd))
        shell_setenv_add(shell, cmd);
    return 0;
}
