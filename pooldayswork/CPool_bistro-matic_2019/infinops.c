/*
** EPITECH PROJECT, 2019
** Infinop.c
** File description:
** Infinite operations
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "bistro.h"

char *infinadd(char *nb1, char *nb2)
{
    int carry = 0;
    int i = 0;
    char *res = malloc(sizeof(char) * (my_strlen(nb1) + 2));

    res[my_strlen(nb1) + 2] = '\0';
    fill_zero(res);
    for ( ; i < my_strlen(nb1); i++) {
        res[i] = (DEC(nb1[i]) + DEC(nb2[i]) + carry) % 10 + '0';
        if (DEC(nb1[i]) + DEC(nb2[i]) + carry >= 10)
            carry = 1;
        else
            carry = 0;
    }
    res[i] = (carry == 1) ? '1' : '0';
    rm_zero(res);
    char *revres = my_revstrdup(res);
    free(res);
    return revres;
}

char *infinsub(char *nb1, char *nb2, int neg)
{
    int carry, i = 0;
    char *res = malloc(sizeof(char) * (my_strlen(nb1) + 2));
    res[my_strlen(nb1) + 2] = '\0';
    fill_zero(res);

    for ( ; i < my_strlen(nb1); i++) {
        if (DEC(nb1[i]) - DEC(nb2[i]) - carry < 0) {
            res[i] = 10 - DEC(nb2[i]) - DEC(nb1[i]) - carry + '0';
            carry = 1;
        } else {
            res[i] = DEC(nb1[i]) - DEC(nb2[i]) - carry + '0';
            carry = 0;
        }
    }
    res[i] = (neg) ? '-' : res[i];
    rm_zero(res);
    char *revres = my_revstrdup(res);
    free(res);
    return revres;
}

/*char *infinmul(char *nb1, char *nb2, int neg)
{
    int carry = 0;
    char *res = malloc(sizeof(char) * (my_strlen(nb1) + my_strlen(nb2) + 2));
    char **subres = malloc(sizeof(char*) * my_strlen(nb2) + 1);
    res[my_strlen(nb1) + my_strlen(nb2) + 2] = '\0';
    subres[my_strlen(nb2) + 1] = NULL;
    fill_zero(res);
    for (int i = 0; i < my_strlen(nb2) + 1; i++) {
        subres[i] = malloc(sizeof(char) * (my_strlen(nb1) + my_strlen(nb2)));
        subres[i][my_strlen(nb1) + my_strlen(nb2)] = '\0';
        fill_zero(subres[i]);
        for (int j = 0; nb1[j] != '\0'; j++) {

        }
    }
    }*/

char *infindiv(char *nb1, char *nb2, int mod)
{
    int i = 0;
    for (; is_higher_sp(nb1, nb2); i++) {
        nb1 = send_sub(nb1, nb2);
    }
    if (mod)
        return nb1;
    return int_to_char(i);
}
