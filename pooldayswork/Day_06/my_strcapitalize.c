/*
** EPITECH PROJECT, 2019
** my_strcapitalize
** File description:
** Capitalize first letter of each word
*/

#include <stddef.h>

char *my_strcapitalize(char *str)
{
    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] -= 32;
    int trigger = 0;
    for (size_t i = 1; str[i] != 0; i++) {
        if (str[i - 1] <= '/' && str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        else if (str[i - 1] <= '@' && str[i - 1] >= ':' && str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        else if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }
}
