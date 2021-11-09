/*
** EPITECH PROJECT, 2020
** miscellaneous functions
** File description:
** a
*/

#include <stdlib.h>
#include "minishell.h"
#include "my.h"
#include "a_malloc.h"

char *env_getvar(char **envp, char *var)
{
    int i = 0;
    char *env_cp;
    for (i = 0; envp[i] != NULL; i++) {
        env_cp = my_strdup(envp[i]);
        if (!my_strcmp(copy_until(&env_cp, '='), var))
            break;
    }
    if (envp[i] == NULL)
        return NULL;
    return env_cp;
}

int env_checkvar(char **envp, char *var)
{
    int i = 0;
    char *env_cp;
    for (i = 0; envp[i] != NULL; i++) {
        for (; envp[i] != NULL && envp[i][0] == '\0'; i++);
        if (envp[i] == NULL)
            break;
        env_cp = my_strdup(envp[i]);
        if (!my_strcmp(copy_until(&env_cp, '='), var))
            break;
    }
    if (envp[i] == NULL)
        return -1;
    return i;
}

char *copy_until(char **str, char c)
{
    int i = 0;
    char *copy;
    for (; (*str)[i] != c; i++);
    copy = a_malloc((sizeof(char) * i + 1) | A_LIST(1));
    for (i = 0; (*str)[i] != c; i++)
        copy[i] = (*str)[i];
    copy[i] = '\0';
    (*str) += i + 1;
    return copy;
}

char *shell_strcat(char *str1, char *str2)
{
    char *r = a_malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 1));
    int i = 0;
    for (int j = 0; str1[j] != '\0'; i++, j++)
        r[i] = str1[j];
    for (int j = 0; str2[j] != '\0'; i++, j++)
        r[i] = str2[j];
    r[i] = '\0';
    return r;
}

int get_occurences(char *str, char c)
{
    int occ = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        occ += (str[i] == c) ? 1 : 0;
    }
    return occ;
}
