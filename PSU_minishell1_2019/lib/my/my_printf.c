/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** a
*/

#include <stddef.h>
#include <stdarg.h>
#include "my.h"

int printf_char_flag_redirect(char c, char *str)
{
    if (c == 's')
        my_putstr(str);
    else if (c == 'S')
        printf_flag_cs(str);
    return 0;
}

int printf_modulo_redirect(char *str, va_list ap)
{
    int i = 0;
    if (!is_int_flag(str[i]) && str[i] != '#' && str[i] != '%' &&
    str[i] != 's' && str[i] != 'S' && str[i] != 'l') {
        my_putchar('%');
        return i - 1;
    }
    if (str[i] == '%') {
        my_putchar('%');
        return i;
    }
    if (str[i] == '#')
        i += alternate_print(str);
    if (str[i] == 'l' || is_int_flag(str[i]))
        i += long_flag_check_redirect(str + i, va_arg(ap, long long));
    else if (str[i] == 's' || str[i] == 'S')
        i += printf_char_flag_redirect(str[i], va_arg(ap, char*));
    return i;
}

int my_printf(char *str, ...)
{
    va_list ap;
    va_start(ap, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%') {
            i++;
            i += printf_modulo_redirect(str + i, ap);
        }
        else
            my_putchar(str[i]);
    }
    va_end(ap);
    return 0;
}
