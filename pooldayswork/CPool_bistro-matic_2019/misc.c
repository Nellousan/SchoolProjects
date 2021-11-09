/*
** EPITECH PROJECT, 2019
** misc.c
** File description:
** miscellaneous functions
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "bistro.h"

char *len_equalize(char *str1, char *str2)
{
    int lendiff = my_strlen(str1) - my_strlen(str2);
    char *buffer = malloc(sizeof(char) * (my_strlen(str1) + 1));
    int i = 0;
    for (; i < my_strlen(str2); i++)
        buffer[i] = str2[i];
    for (; i < lendiff + my_strlen(str2); i++)
        buffer[i] = '0';
    buffer[i] = '\0';
    return buffer;
}

void fill_res(char *res, char *res_base)
{
    for (int i = 0; i < 2048; i++)
        res[i] = res_base[0];
    res[2047] = '\0';
    return;
}

void add_end(char *res, char *res_base)
{
    for (int i = 2046; res[i] == res_base[0]; i--)
        res[i] = '\0';
    return;
}

void fill_zero(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = '0';
    return;
}

void rm_zero(char *str)
{
    for (int i = my_strlen(str) - 1; str[i] == '0'; i--)
        str[i] = '\0';
    return;
}
