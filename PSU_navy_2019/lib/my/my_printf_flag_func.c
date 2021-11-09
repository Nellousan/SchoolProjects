/*
** EPITECH PROJECT, 2019
** printf flag funcs
** File description:
** a
*/

#include "my.h"
#include <stdlib.h>

void printf_flag_cc(long long nb)
{
    return;
}

void printf_flag_o(long long nb)
{
    char *str = my_llint_to_char(nb);
    char *octstr = my_convert_base(str, "0123456789", "01234567");
    my_putstr(octstr);
    free(str);
    free(octstr);
    return;
}

void printf_flag_u(long long nb)
{
    if (nb < 0)
        nb = -nb;
    my_putllnbr(nb);
    return;
}

void printf_flag_x(long long nb)
{
    char *str = my_llint_to_char(nb);
    char *hexstr = my_convert_base(str, "0123456789", "0123456789abcdef");
    my_putstr(hexstr);
    free(str);
    free(hexstr);
    return;
}

void printf_flag_cx(long long nb)
{
    char *str = my_llint_to_char(nb);
    char *hexstr = my_convert_base(str, "0123456789", "0123456789ABCDEF");
    my_putstr(hexstr);
    free(str);
    free(hexstr);
    return;
}
