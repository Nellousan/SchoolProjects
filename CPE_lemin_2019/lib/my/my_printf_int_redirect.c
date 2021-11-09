/*
** EPITECH PROJECT, 2019
** printf int redirection functions
** File description:
** a
*/

#include <stddef.h>
#include <stdarg.h>
#include "my.h"

void printf_int_flag_redirect(char c, long long nb)
{
    flag_t flag_s[] = {{'C', &printf_flag_cc}, {'o', &printf_flag_o},
        {'u', &printf_flag_u}, {'x', &printf_flag_x}, {'X', &printf_flag_cx},
        {'b', &printf_flag_b}, {'d', &printf_flag_d}, {'i', &printf_flag_d},
        {'p', &printf_flag_p}, {'\0', NULL}};
    if (c == 'c') {
        my_putchar(nb);
        return;
    }
    for (int i = 0; flag_s[i].c != '\0'; i++)
        if (flag_s[i].c == c) {
            flag_s[i].fptr(nb);
            return;
        }
    return;
}

int is_int_flag(char c)
{
    if (c == 'c' || c == 'C' || c == 'o' || c == 'u' || c == 'x' ||
        c == 'X' || c == 'b' || c == 'd' || c == 'i' || c == 'p')
        return 1;
    else
        return 0;
}

int long_flag_check_redirect(char *str, long long nb)
{
    if (is_int_flag(str[0])) {
        nb << 32 >> 32;
        printf_int_flag_redirect(str[0], nb);
        return 0;
    } else if (str[0] == 'l' && is_int_flag(str[1])){
        printf_int_flag_redirect(str[1], nb);
        return 1;
    } else {
        printf_int_flag_redirect(str[2], nb);
        return 2;
    }
}

int alternate_print(char *str)
{
    int i = 1;
    for (; str[i] == 'l'; i++);
    if (str[i] == 'x' || str[i] == 'X')
        my_putstr("0x");
    else if (str[i] == 'o')
        my_putchar('0');
    return 1;
}
