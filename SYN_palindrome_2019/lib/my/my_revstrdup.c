/*
** EPITECH PROJECT, 2019
** my_revstr remade
** File description:
** reverse string
*/

#include <stdlib.h>
#include "a_malloc.h"

char *my_strdup(char *str);
int my_strlen(char const *str);

char *my_revstrdup(char const *str)
{
    char *buffer = a_malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = my_strlen(str) - 1;
    int j = 0;
    for (; i >= 0; i--) {
        buffer[j] = str[i];
        j++;
    }
    buffer[j] = '\0';
    return buffer;
}
