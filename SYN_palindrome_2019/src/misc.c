/*
** EPITECH PROJECT, 2020
** miscellaneous
** File description:
** c
*/

#include "my.h"
#include "palindrome.h"
#include "a_malloc.h"

void reverse(char *str)
{
    char *cstr = my_strdup(str);
    int len = my_strlen(str);
    int ilen = len - 1;
    int i = 0;
    for (; i < len; i++, ilen--)
        str[i] = cstr[ilen];
    return;
}

char *my_itoa(int nb)
{
    char *str = a_malloc(sizeof(char) * 15);
    int i = 0;
    bool neg = false;
    if (nb < 0) {
        neg = true;
        str++;
    }
    while (nb > 0) {
        str[i] = (nb % 10) + '0';
        nb /= 10;
        i++;
    }
    str[i] = '\0';
    reverse(str);
    if (neg)
        str--;
    return str;
}

int my_atoi(char *str)
{
    int neg = 0;
    int nb = 0;
    if (str[0] == '-') {
        str++;
        neg = 1;
    }
    for (int i = 0; str[i] != '\0'; i++)
        nb += DEC(str[i]) * my_pow(10, my_strlen(str) - (i + 1));
    if (neg)
        nb = -nb;
    return nb;
}
