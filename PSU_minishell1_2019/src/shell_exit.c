/*
** EPITECH PROJECT, 2020
** shell exit
** File description:
** a
*/

#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"
#include "my.h"
#include "a_malloc.h"

int shell_exit(shell_t *shell, char **cmd)
{
    int exit_status = EXIT;
    if (my_array_size(cmd) != 1) {
        my_printf("exit: Expression Syntax.\n");
        return 1;
    }
    if (isatty(0))
        my_printf("exit\n");
    free(ENVP);
    a_malloc(A_MALLOC_FREE | A_LIST(2));
    a_malloc(A_MALLOC_FREE | A_LIST(1));
    a_malloc(A_MALLOC_FREE);
    exit(exit_status);
}
