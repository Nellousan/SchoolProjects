/*
** EPITECH PROJECT, 2019
** stdarg bootstrap my_printf
** File description:
** 
*/

#include <stdarg.h>
#include "lib/my/my.h"

int sum_stdarg(int i, int nb, ...)
{
    va_list ap;
    int res = 0;
    va_start(ap, nb);
    if (!i)
        for (int i = 0; i < nb; i++)
            res += va_arg(ap, int);
    else if (i)
        for (int i = 0; i < nb; i++)
            res += my_strlen(va_arg(ap, char *));
    va_end(ap);
    return res;
}

int disp_stdarg(char *s, ...)
{
    va_list ap;
    va_start(ap, s);
    for(int i = 0; s[i] != '\0'; i++) {
        switch(s[i]) {
        case 'c':
            my_putchar(va_arg(ap, int));
            break;
        case 's':
            my_putstr(va_arg(ap, char *));
            break;
        case 'i':
            my_putnbr(va_arg(ap, int));
            break;
        default:
            my_putstr("syntax error with first arg of disp_stdarg");
            va_end(ap);
            return 84;
            break;
        }
        my_putchar('\n');
    }
    va_end(ap);
    return 0;
}
