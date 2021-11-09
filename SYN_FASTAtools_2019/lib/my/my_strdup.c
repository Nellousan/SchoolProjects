/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** return copy of a string
*/

#include <stdlib.h>
#include <stddef.h>
#include "a_malloc.h"

int my_strlen(char const *str);

char *my_strdup(char const *str)
{
    char *buffer = a_malloc(sizeof(char) * (my_strlen(str) + 1));
    for (size_t i = 0; i < my_strlen(str) + 1; i++)
        buffer[i] = str[i];
    return buffer;
}

char *my_astrdup(char const *str, int list)
{
    char *buffer = a_malloc(sizeof(char) * (my_strlen(str) + 1) | A_LIST(list));
    for (size_t i = 0; i < my_strlen(str) + 1; i++)
        buffer[i] = str[i];
    return buffer;
}
