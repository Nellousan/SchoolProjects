/*
** EPITECH PROJECT, 2019
** my_atoi
** File description:
** my_atoi
*/

#include "../../include/my.h"
#include <stdio.h>

int change_nbr_to_neg(int nbr, int count_neg)
{
    if (count_neg == 1) {
        nbr *= -1;
    }
    return nbr;
}

int verif_neg(char const *str, int i)
{
    int count_neg = 0;

    if (str[0] == '-') {
        i = 1;
        count_neg = 1;
    }
    return count_neg;
}

int my_atoi(char const *str)
{
    int i = 0;
    long long nbr = 0;
    int count_neg = 0;

    for (i = 0; str[i]; i++) {
        count_neg = verif_neg(str, i);
        if (count_neg == 1 && i == 0)
            i = 1;
        if (str[i] >= '0' && str[i] <= '9') {
            nbr += str[i] - 48;
            nbr *= 10;
        }
        else if (str[i] < '0' || str[i] > '9') {
            nbr /= 10;
            return nbr;
        }
    }
    nbr /= 10;
    nbr = change_nbr_to_neg(nbr, count_neg);
    return (int)nbr;
}
