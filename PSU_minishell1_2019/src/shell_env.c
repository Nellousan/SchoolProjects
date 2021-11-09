/*
** EPITECH PROJECT, 2020
** shell_env
** File description:
** aa
*/

#include <stdlib.h>
#include "minishell.h"
#include "my.h"

int shell_env(shell_t *shell, UNUSED char **cmd)
{
    for (int i = 0; ENVP[i] != NULL; i++) {
        if (ENVP[i][0] != '\0')
            my_printf("%s\n", ENVP[i]);
    }
    return 0;
}
