/*
** EPITECH PROJECT, 2019
** my convert misc
** File description:
** a
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "a_malloc.h"

void my_convert_add_end(char *res, char *res_base)
{
    for (int i = 1022; res[i] == res_base[0]; i--)
        res[i] = '\0';
    return;
}

void my_convert_fill_res(char *res, char *res_base)
{
    for (int i = 0; i < 1024; i++)
        res[i] = res_base[0];
    res[1023] = '\0';
    return;
}

void my_convert_fill_zero(char *str, int end)
{
    for (int i = 0; i < end; i++)
        str[i] = '0';
    return;
}

char *my_int_to_char(int nb)
{
    if (nb == 0)
        return my_strdup("0");
    char *str = a_malloc(sizeof(char) * 16);
    int i = 0;
    str[15] = '\0';
    my_convert_fill_zero(str, 15);
    for (; nb > 0; i++) {
        str[i] = nb % 10 + '0';
        nb /= 10;
    }
    str[i] = '\0';
    char *revstr = my_revstrdup(str);
    free(str);
    return revstr;
}

char *my_llint_to_char(long long nb)
{
    if (nb == 0)
        return my_strdup("0");
    char *str = a_malloc(sizeof(char) * 32);
    int i = 0;
    str[31] = '\0';
    my_convert_fill_zero(str, 31);
    for (; nb > 0; i++) {
        str[i] = nb % 10 + '0';
        nb /= 10;
    }
    str[i] = '\0';
    char *revstr = my_revstrdup(str);
    free(str);
    return revstr;
}
