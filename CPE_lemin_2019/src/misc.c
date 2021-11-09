/*
** EPITECH PROJECT, 2020
** misc.
** File description:
** c
*/

#include "a_malloc.h"
#include "my.h"

int my_atoi(char *str)
{
    int neg = 0;
    int nb = 0;
    if (str[0] == '-') {
        str++;
        neg = 1;
    }
    for (int i = 0; str[i] != '\0'; i++)
        nb += (str[i] - '0') * my_pow(10, my_strlen(str) - (i + 1));
    if (neg) {
        nb = -nb;
        str--;
    }
    return nb;
}

char *cpdelim(char **str, char c, int list)
{
    int i = 0;
    char *copy;
    for (; (*str)[i] != c && (*str)[i] != '\0'; i++);
    copy = a_malloc(sizeof(char) * (i + 1) | A_LIST(list));
    for (i = 0; (*str)[i] != c && (*str)[i] != '\0'; i++)
        copy[i] = (*str)[i];
    copy[i] = '\0';
    if ((*str)[i] == '\0')
        (*str) += i;
    else
        (*str) += i + 1;
    return copy;
}
