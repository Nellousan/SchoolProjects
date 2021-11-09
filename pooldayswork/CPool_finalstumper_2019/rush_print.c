/*
** EPITECH PROJECT, 2019
** rush print
** File description:
**
*/

#include "my.h"

int first_len(char *buffer);
int count_ret(char *buffer);

int print_rush_one(char *buffer)
{
    my_putstr("[rush1-1] ");
    my_putnbr(first_len(buffer));
    my_putchar(' ');
    my_putnbr(count_ret(buffer));
    my_putchar('\n');
}

int print_rush_two(char *buffer)
{
    my_putstr("[rush1-2] ");
    my_putnbr(first_len(buffer));
    my_putchar(' ');
    my_putnbr(count_ret(buffer));
    my_putchar('\n');
}

int print_rush_three(char *buffer)
{
    my_putstr("[rush1-3] ");
    my_putnbr(first_len(buffer));
    my_putchar(' ');
    my_putnbr(count_ret(buffer));
    my_putchar('\n');
}

int print_rush_four(char *buffer)
{
    my_putstr("[rush1-4] ");
    my_putnbr(first_len(buffer));
    my_putchar(' ');
    my_putnbr(count_ret(buffer));
    my_putchar('\n');
}

int print_rush_five(char *buffer)
{
    my_putstr("[rush1-5] ");
    my_putnbr(first_len(buffer));
    my_putchar(' ');
    my_putnbr(count_ret(buffer));
    my_putchar('\n');
}
