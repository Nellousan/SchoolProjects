/*
** EPITECH PROJECT, 2019
** evalexpr bootstrap
** File description:
** 
*/

#include <stdlib.h>
#include "my.h"

int factors(char **str);
int summands(char **str);

int is_charnum(char c)
{
    if (c <= '9' && c >= '0')
        return 1;
    return 0;
}

int number(char **str)
{
    int nb = 0;
    int i = 0;
    for (i; is_charnum(str[0][i]); i++);
    i--;
    for (int j = 0; i >= 0; j++) {
        nb += (str[0][i] - '0') * my_pow(10, j);
        i--;
    }
    for (i = 0; is_charnum(str[0][i]); i++);
    *str += i;
    return nb;
}

int parentheses(char **str)
{
    str[0]++;
    int nb = summands(str);
    return nb;
        
}

int factors(char **str)
{
    int nb = 0;
    if (str[0][0] == '(') {
        str[0]++;
        nb = summands(str);

    } else
        nb = number(str);
    while (str[0][0] != '+' && str[0][0] != '-' && str[0][0] != '\0' && str[0][0] != ')') {
        if (str[0][0] == '*') {
            str[0]++;
            if (str[0][0] == '(') {
                str[0]++;
                nb *= summands(str);
            } else {
                nb *= number(str);
                my_putnbr(nb);
                my_putchar('\n');
            }
        }
        else if (str[0][0] == '/') {
            str[0]++;
            if (str[0][0] == '(') {
                str[0]++;
                nb /= summands(str);
            } else
                nb /= number(str);
        }
    }
    if (str[0][0] != ')')
        str[0]++;
    return nb;
}

int summands(char **str)
{
    int nb = 0;
    if (str[0][0] == '(') {
        str[0]++;
        nb = summands(str);

    } else
        nb = number(str);
    while (str[0][0] != '\0' && str[0][0] != ')') {
        if (str[0][0] == '+') {
            str[0]++;
            if (str[0][0] == '(') {
                str[0]++;
                nb += summands(str);
            } else
                nb += factors(str);
        } else if (str[0][0] == '-') {
            str[0]++;
            if (str[0][0] == '(') {
                str[0]++;
                nb -= summands(str);
            } else
                nb -= factors(str);
        }
    }
    if (str[0][0] != ')')
        str[0]++;
    return nb;
}

int main(int argc, char **argv)
{
    char *str = my_strdup(argv[1]);
    my_putnbr(summands(&str));
}
