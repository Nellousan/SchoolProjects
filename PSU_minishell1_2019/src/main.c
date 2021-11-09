/*
** EPITECH PROJECT, 2020
** minishel main
** File description:
** a
*/

#include <unistd.h>
#include "minishell.h"
#include "a_malloc.h"
#include "my.h"

int main(UNUSED int argc, UNUSED char **argv, char **envp)
{
    shell_t *shell = shell_load(envp);
    shell_prompt(shell);
    a_malloc(A_MALLOC_FREE);
    return 0;
}
