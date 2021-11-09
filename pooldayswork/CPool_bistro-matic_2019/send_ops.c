/*
** EPITECH PROJECT, 2019
** send ops
** File description:
** preparative functions for infinops
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "bistro.h"

char *send_add(char *nb1, char *nb2)
{
    char *revnb1 = my_revstrdup(nb1);
    char *revnb2 = my_revstrdup(nb2);
    int lendiff = my_strlen(revnb1) - my_strlen(revnb2);
    char *res = NULL;
    if (!check_char_base(nb1[0], "0123456789")) {
        nb1++;
        return send_sub(nb2, nb1);
    }
    if (lendiff > 0)
        revnb2 = len_equalize(revnb1, revnb2);
    else if (lendiff < 0)
        revnb1 = len_equalize(revnb2, revnb1);
    res = infinadd(revnb1, revnb2);
    free(revnb1);
    free(revnb2);
    if (res[0] == '0') {
        my_putchar('0');
        exit(0);
    }
    return res;
}

char *send_sub(char *nb1, char *nb2)
{
    char *revnb1 = my_revstrdup(nb1);
    char *revnb2 = my_revstrdup(nb2);
    int lendiff = my_strlen(revnb1) - my_strlen(revnb2);
    char *res = NULL;
    if (!check_char_base(nb1[0], "0123456789")) {
        nb1++;
        return send_add(nb1, nb2);
    } if ((lendiff > 0) || (!lendiff && is_higher(nb1, nb2))) {
        revnb2 = len_equalize(revnb1, revnb2);
        res = infinsub(revnb1, revnb2, 0);
    } else if ((lendiff < 0) || (!lendiff && is_higher(nb2, nb1))) {
        revnb1 = len_equalize(revnb2, revnb1);
        res = infinsub(revnb2, revnb1, 1);
    } free(revnb1);
    free(revnb2);
    if (res[0] == '0') {
        my_putchar('0');
        exit(0);
    }
    res[0] = (res[0] == '\0') ? '0' : res[0];
    return res;
}

char *send_div(char *nb1, char *nb2, int mod)
{
    char *res = infindiv(nb1, nb2, mod);
    if (res[0] == '0') {
        my_putchar('0');
        exit(0);
    }
    return res;
}
