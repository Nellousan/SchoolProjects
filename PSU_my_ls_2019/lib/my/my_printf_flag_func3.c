/*
** EPITECH PROJECT, 2019
** aaa
** File description:
** aaa
*/

#include "my.h"
#include <stdlib.h>

void printf_flag_cs_b(char c)
{
    int ic = c;
    char *str;
    char *octstr;
    my_putchar('\\');
    if (ic < 0) {
        my_putchar('-');
        ic = -ic;
    }
    str = my_int_to_char(ic);
    octstr = my_convert_base(str, "0123456789", "01234567");
    if (my_strlen(octstr) == 2)
        my_putchar('0');
    if (my_strlen(octstr) == 1)
        my_putchar('0');
    my_putstr(octstr);
    free(str);
    free(octstr);
    return;
}

void printf_flag_cs(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            printf_flag_cs_b(str[i]);
        } else
            my_putchar(str[i]);
    }
    return;
}
