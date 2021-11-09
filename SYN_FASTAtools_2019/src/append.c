/*
** EPITECH PROJECT, 2020
** append
** File description:
** c
*/

#include <stddef.h>
#include "my.h"
#include "a_malloc.h"
#include "fasta.h"

void append(char ***tab, char *str, int list, bool dupsec)
{
    int len = 0;
    char **newtab = NULL;
    int i = 0;
    for (int i = 0; (*tab)[i] != NULL && dupsec; i++)
        if (!my_strcmp((*tab)[i], str))
            return;
    for (len = 0; (*tab)[len] != NULL; len++);
    newtab = a_malloc(sizeof(char *) * (len + 2) | A_LIST(list));
    for (i = 0; (*tab)[i] != NULL; i++)
        newtab[i] = (*tab)[i];
    newtab[i] = str;
    newtab[i + 1] = NULL;
    (*tab) = newtab;
    return;
}
