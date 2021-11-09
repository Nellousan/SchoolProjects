/*
** EPITECH PROJECT, 2019
** my_strupcase
** File description:
** replace every lowercases by uppercases
*/

#include <stddef.h>

char *my_strupcase(char *str)
{
    for (size_t i = 0; str[i] != '\0'; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    return str;
}
