/*
** EPITECH PROJECT, 2020
** shell prompt
** File description:
** a
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include "minishell.h"
#include "my.h"
#include "a_malloc.h"

int shell_prompt_read_eof_management(char *buffer)
{
    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '\n') {
            buffer[i] = '\0';
        }
    return 0;
}

char **shell_prompt_read(shell_t *shell)
{
    size_t n = 0;
    char *buffer = NULL;
    ssize_t size = getline(&buffer, &n, stdin);
    char **cmd;
    if (size == 0 || size == -1) {
        shell_exit(shell, my_str_to_array(my_strdup("exit")));
    }
    if (buffer[0] == '\n')
        return NULL;
    buffer[size] = '\0';
    shell_prompt_read_eof_management(buffer);
    cmd = my_str_to_array(my_strdup(buffer));
    free(buffer);
    return cmd;
}

char *shell_prompt_print_getcwd(shell_t *shell, char *cwd)
{
    int slash = 0;
    int slash2 = 0;
    int slash_c = 0;
    int i = 0;
    int j = 0;
    char *cwd_f;
    for (i = 0; cwd[i] != '\0'; i++)
        slash_c += (cwd[i] == '/') ? 1 : 0;
    for (i = 0; slash != slash_c - 1; i++)
        slash += (cwd[i] == '/') ? 1 : 0;
    for (j = 0; slash2 != slash_c; j++)
        slash2 += (cwd[j] == '/') ? 1: 0;
    cwd_f = my_strdup(cwd + i);
    if (!my_strcmp(copy_until(&cwd_f, '/'), ENV->user)) {
        cwd_f = shell_strcat("~/", cwd + j);
    } else if (!my_strcmp(copy_until(&cwd_f, '\0'), ENV->user)) {
        cwd_f = my_strdup("~");
    } else {
        cwd_f = cwd + j;
    } return cwd_f;
}

int shell_prompt_print(UNUSED shell_t *shell)
{
    if (!isatty(0))
        return 0;
    my_printf("$> ");
    return 0;
}

int shell_prompt(shell_t *shell)
{
    char **cmd = NULL;
    while (1) {
        while (!cmd) {
            shell_prompt_print(shell);
            cmd = shell_prompt_read(shell);
        }
        shell_cmd(shell, cmd);
        cmd = NULL;
        a_malloc(A_MALLOC_FREE);
    }
    return 0;
}
