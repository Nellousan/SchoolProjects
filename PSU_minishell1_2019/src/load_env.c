/*
** EPITECH PROJECT, 2020
** load env
** File description:
** a
*/

#include <stdlib.h>
#include "minishell.h"
#include "a_malloc.h"
#include "my.h"

char *env_load_get_prompt(env_t *env)
{
    char *prompt = my_astrdup(shell_strcat(env->user, "@"), 1);
    char *host_cp = my_astrdup(env->hostname, 1);
    prompt = my_astrdup(shell_strcat(prompt, copy_until(&host_cp, '.')), 1);
    return prompt;
}

char **env_copy(char **envp)
{
    char **copy = malloc(sizeof(char *) * (my_array_size(envp) + 1));
    int i = 0;
    for (i = 0; envp[i] != NULL; i++)
        copy[i] = my_astrdup(envp[i], 1);
    copy[i] = NULL;
    return copy;
}

env_t *env_load(char **envp)
{
    env_t *env = a_malloc(sizeof(env_t) | A_LIST(1));
    env->envp = env_copy(envp);
    return env;
}
