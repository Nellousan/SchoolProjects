/*
** EPITECH PROJECT, 2019
** my_strlowcase
** File description:
** replace every uppercases by lowercases
*/

#include <stddef.h>

char *my_strlowcase(char *str)
{
    for (size_t i = 0; str[i] != '\0'; i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    return str;
}
