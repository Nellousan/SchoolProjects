/*
** EPITECH PROJECT, 2019
** my_revstr remade
** File description:
** reverse string
*/

#include <stdlib.h>

char *my_strdup(char *str);
int my_strlen(char const *str);

char *my_revstrdup(char const *str)
{
    char *buffer = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = my_strlen(str) - 1;
    int j = 0;
    for (i; i >= 0; i--) {
        buffer[j] = str[my_strlen(str) - i];
        j++;
    }
    return buffer;
}
