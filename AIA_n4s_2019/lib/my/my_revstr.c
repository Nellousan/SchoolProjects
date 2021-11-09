/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** Day06 task03
*/

#include <stdlib.h>
#include <unistd.h>

int strl(const char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

char *my_revstr(char *str)
{
    char *dest = malloc(sizeof(char) * (strl(str)) + 1);
    int t = strl(str);
    int i = 1;

    while (i <= t) {
        dest[i - 1] = str[t - i];
        i++;
    }
    dest[i - 1] = '\0';
    return dest;
}
