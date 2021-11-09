/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** concatenate strings
*/

#include <stddef.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    size_t dest_length = my_strlen(dest);
    size_t i = 0;
    for (i = 0; src[i] != '\0'; i++) 
        dest[dest_length + i] = src[i];
    dest[dest_length + i] = '\0';
    return dest;
}
