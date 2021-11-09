/*
** EPITECH PROJECT, 2019
** infinadd
** File description:
** 
*/

#include <stdlib.h>
#include "my.h"
#define ABS(value) (((value) < 0) ? (-(value)) : ((value)))

int my_putstr_sp(char const *str)
{
    int i = (str[0] == '@') ? 1 : 0;
    while (str[i] != '\0') {
        if (str[i] == '@')
            i++;
        my_putchar(str[i]);
        i++;
    }
}

int get_lendiff(char *str1, char *str2)
{
    int str1len = my_strlen(str1);
    int str2len = my_strlen(str2);
    return str1len - str2len;
}

char *char_add(char *str1, char *str2, int neg)
{
    char *res = malloc(sizeof(char) * (my_strlen(str1) + 3));
    int carry = 0;
    res[0] = '@';
    res[1] = '@';
    res[my_strlen(str1) + 2] = '\0';
    int i = my_strlen(str1) - 1;
    for (i; i >= 0; i--) {
        res[i + 2] = (str1[i] - '0' + str2[i] - '0' + carry) % 10 + '0';
        if (str1[i] - '0' + str2[i] - '0' + carry >= 10) {
            res[i + 1] = (res[i + 1] == '@') ? '1' : res[i + 1];
            carry = 1;
        } else
            carry = 0;
    }
    if (neg != 0)
        res[0] = '-';
    return res;
}

char *char_sub(char *str1, char *str2)
{
    char *res = malloc(sizeof(char) * (my_strlen(str1) + 2));
    int carry = 0;
    res[0] = '@';
    res[my_strlen(str1) + 1] = '\0';
    int i = my_strlen(str1) - 1;
    for (i; i >= 0; i--) {
        res[i + 1] = (res[i + 1] == ':') ? '0' : res[i + 1];
        if (str1[i]  - str2[i] - carry < 0) {
            res[i + 1] = 10 - ABS(str1[i] - str2[i] - carry) + '0';
            carry = 1;
        }
        else {
            res[i + 1] = ABS(str1[i] - str2[i] - carry) + '0';
            carry = 0;
        }
        for (int i2 = 0; res[i2] == '0' || res[i2] == '@'; i2++)
            res[i2] = '@';
    }
    return res;
}

char *len_equalize(char *str1, char *str2)
{
    int lendiff = get_lendiff(str1, str2);
    int i = 0;
    int i2 = (str2[0] == '-') ? 1 : 0;
    char *buffer = malloc(sizeof(char) * my_strlen(str1) + 1);
    if (str1[0] == '-')
        str1[0] = '0';
    if (str2[0] == '-') {
        str2[0] = '0';
        lendiff++;
    }
    for (lendiff; lendiff != 0; lendiff--) {
        buffer[i] = '0';
        i++;
    }
    for (i2; str2[i2] != 0; i2++) {
        buffer[i] = str2[i2];
        i++;
    }
    if (str1[0] == '0' && buffer[0] == '0') {
        for (int i = 0; i < my_strlen(str1); i++) {
            buffer[i] = buffer[i + 1];
            str1[i] = str1[i + 1];
        }
    }
    free(str2);
    return buffer;
}

char *infinadd(char *argv1, char *argv2)
{
    char *str1 = my_strdup(argv1);
    char *str2 = my_strdup(argv2);
    char *res;
    int neg1 = (str1[0] == '-') ? 1 : 0;
    int neg2 = (str2[0] == '-') ? 1 : 0;
    int neg = neg1 + neg2;
    if (my_strlen(str1) > my_strlen(str2))
        str2 = len_equalize(str1, str2);
    else
        str1 = len_equalize(str2, str1);
    if (neg == 0 || neg == 2)
        res = char_add(str1, str2, neg);
    else {
        if (neg1 && my_strlen(argv1) - 1 < my_strlen(argv2))
            res = char_sub(str2, str1);
        else if (neg1 && my_strlen(argv1) - 1 > my_strlen(argv2)) {
            res = char_sub(str1, str2);
            res[0] = '-';
        } else if (neg2 && my_strlen(argv2) - 1 < my_strlen(argv1))
            res = char_sub(str1, str2);
        else if (neg2 && my_strlen(argv2) - 1 > my_strlen(argv1)) {
            res = char_sub(str2, str1);
            res[0] = '-';
        } else if (neg1)
            res = char_sub(str2, str1);
        else if (neg2)
            res = char_sub(str1, str2);
    }
    return res;
}
