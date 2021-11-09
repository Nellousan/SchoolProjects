/*
** EPITECH PROJECT, 2020
** hdap
** File description:
** adja
*/

#include "palindrome.h"
#include "my.h"
#include "a_malloc.h"

int convert_base_int(char *str, int base)
{
    int nb = 0;
    int len = my_strlen(str);
    for (int i = 0; i < len; i++)
        nb += (str[i] - '0') * my_pow(base, (len - 1) - i);
    return nb;
}

char *convert_base_str(int nb, int base)
{
    char *str = a_malloc(sizeof(char) * 32);
    int i = 0;
    while (nb > 0) {
        if (nb >= base)
            str[i] = (nb % base) + '0';
        else
            str[i] = nb + '0';
        nb /= base;
        i++;
    }
    str[i] = '\0';
    reverse(str);
    return str;
}
