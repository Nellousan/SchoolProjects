/*
** EPITECH PROJECT, 2019
** my_itoa
** File description:
** my_itoa
*/

#include "../../include/my.h"

char *my_itoa(int nb, char *str)
{
    int i = 0;
    int j = nb;
    int len = 0;

    while (j > 0) {
        j /= 10;
        len++;
    }
    str = malloc(sizeof(char) * len + 1);
    for (i = 0; nb != 0; i++) {
        str[i] = nb % 10 + '0';
        nb /= 10;
    }
    str[len] = '\0';
    str = my_revstr(str);
    return str;
}
