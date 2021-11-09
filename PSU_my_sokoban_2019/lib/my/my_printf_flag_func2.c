/*
** EPITECH PROJECT, 2019
** second part of flag funcs
** File description:
** 
*/

#include "my.h"
#include <stdlib.h>

void printf_flag_d(long long nb)
{
    my_putllnbr(nb);
    return;
}

void printf_flag_c(char c)
{
    my_putchar('c');
    return;
}

void printf_flag_s(char *str)
{
    my_putstr(str);
    return;
}

void printf_flag_p(long long nb)
{
    char *str = my_llint_to_char(nb);
    char *hexstr = my_convert_base(str, "0123456789", "0123456789abcdef");
    my_putstr("0x");
    my_putstr(hexstr);
    free(str);
    free(hexstr);
    return;
}

void printf_flag_b(long long nb)
{
    char *str = my_llint_to_char(nb);
    char *binstr = my_convert_base(str, "0123456789", "01");
    my_putstr(binstr);
    free(str);
    free(binstr);
    return;
}
