/*
** EPITECH PROJECT, 2020
** load path
** File description:
** a
*/

#include <stdlib.h>
#include "minishell.h"
#include "my.h"
#include "a_malloc.h"

char **path_load_basics(void)
{
    char **path = a_malloc(sizeof(char *) * 2 | A_LIST(1));
    path[0] = my_astrdup("/usr/bin", 1);
    path[1] = NULL;
    return path;
}

char **path_load(char **envp)
{
    char *paths;
    int path_c;
    char **path;
    int i = 0;
    if (env_checkvar(envp, "PATH") == -1)
        return path_load_basics();
    paths = env_getvar(envp, "PATH");
    path_c = get_occurences(paths, ':') + 1;
    path = a_malloc(sizeof(char *) * (path_c + 1) | A_LIST(1));
    for (i = 0; i < path_c - 1; i++) {
        path[i] = copy_until(&paths, ':');
    }
    path[i] = copy_until(&paths, '\0');
    path[i + 1] = NULL;
    return path;
}
