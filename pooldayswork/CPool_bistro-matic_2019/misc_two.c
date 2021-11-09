/*
** EPITECH PROJECT, 2019
** misc 2
** File description:
** second part of misc. funcs
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "bistro.h"

int is_higher(char *nb1, char *nb2)
{
    for (int i = 0; nb1[i] != '\0'; i++) {
        if (nb1[i] > nb2[i])
            return 1;
        if (nb1[i] < nb2[i])
            return 0;
    }
    return 1;
}

int char_to_int(char *str)
{
    int nb = 0;
    char *revstr = my_revstrdup(str);
    for (int i = 0; revstr[i] != '\0'; i++) {
        nb += DEC(revstr[i]) * my_pow(10, i);
    }
    free(revstr);
    return nb;
}

char *int_to_char(int nb)
{
    char *str = malloc(sizeof(char) * 16);
    int i = 0;
    str[15] = '\0';
    fill_zero(str);
    for (; nb > 0; i++) {
        str[i] = nb % 10 + '0';
        nb /= 10;
    }
    str[i] = '\0';
    char *revstr = my_revstrdup(str);
    free(str);
    return revstr;
}

int is_higher_sp(char *nb1, char *nb2)
{
    int lendiff = my_strlen(nb1) - my_strlen(nb2);
    char *nb1dup = my_strdup(nb1);
    char *nb2dup = my_strdup(nb2);
    if (lendiff > 0) {
        nb2dup = my_revstrdup(nb2dup);
        nb2dup = len_equalize(nb1, nb2);
        nb2dup = my_revstrdup(nb2dup);
    } else if (lendiff < 0) {
        nb1dup = my_revstrdup(nb1dup);
        nb1dup = len_equalize(nb2, nb1);
        nb1dup = my_revstrdup(nb1dup);
    }
    return is_higher(nb1dup, nb2dup);
}
