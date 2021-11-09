/*
** EPITECH PROJECT, 2019
** base converter funcs
** File description:
** 
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "bistro.h"

int get_base_number(char digit, char *nb_base)
{
    int i = 0;
    for (; nb_base[i] != digit; i++);
    return i;
}

void res_increment_carry(char *res, char *res_base, int base)
{
    int carry = 1;
    for (int j = 0; carry; j++) {
        if (res[j] != res_base[base - 1]) {
            carry = 0;
            res[j] = res_base[get_base_number(res[j], res_base) + 1];
        } else
            res[j] = res_base[0];
    }
    return;
}

void res_increment(char *res, char *res_base, int increment)
{
    int base = my_strlen(res_base);
    for (int i = 0; i < increment; i++) {
        if (res[0] != res_base[base - 1])
            res[0] = res_base[get_base_number(res[0], res_base) + 1];
        else
            res_increment_carry(res, res_base, base);
    }
    return;
}

char *convert_base(char *nb, char *nb_base, char *res_base, char *sym_base)
{
    char *res = malloc(sizeof(char) * 2048);
    int j = 0;
    int neg = 0;
    fill_res(res, res_base);
    if (nb[0] == '-') {
        nb++;
        neg = 1;
    }
    for (int i = my_strlen(nb); i > 0; i--) {
        int increment = get_base_number(nb[i - 1], nb_base);
        increment *= my_pow(my_strlen(nb_base), j++);
        if (increment > 0)
            res_increment(res, res_base, increment);
    }
    add_end(res, res_base);
    if (neg)
        res[my_strlen(res)] = sym_base[3];
    char *revres = my_revstrdup(res);
    free(res);
    return revres;
}
