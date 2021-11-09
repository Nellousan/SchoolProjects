/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** concatenate n-first char of src string into dest string
*/

#include <stddef.h>

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int n)
{
    size_t dest_length = my_strlen(dest);
    size_t i = 0;
    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[dest_length + i] = src[i];
    dest[dest_length + i] = '\0';
    return dest;
}
