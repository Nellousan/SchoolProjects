/*
** EPITECH PROJECT, 2019
** strdup
** File description:
** strdup
*/

#include <stdlib.h>

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

char *my_strdup(char const *src)
{
    int i = 0;
    char *dest;

    dest = malloc(sizeof(char) * (my_strlen(src)));
    while (src[i]) {
        dest[i] = src[i];
        i++;
        dest[i] = '\0';
    }
    return (dest);
}
