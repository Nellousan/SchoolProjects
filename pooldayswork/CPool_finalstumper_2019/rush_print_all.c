/*
** EPITECH PROJECT, 2019
** rush_print_all
** File description:
** rush_print_all
*/

#include "my.h"

int first_len(char *buffer);
int count_ret(char *buffer);

int print_rush_three_four_five(char *str)
{
    int i = 0;
    for (i = 3; i <= 5; i++) {
        my_putstr("[rush1-");
        my_putnbr(i);
        my_putstr("] ");
        my_putnbr(first_len(str));
        my_putchar(' ');
        my_putnbr(count_ret(str));
        if (i != 5)
            my_putstr(" || ");
    }
    my_putchar('\n');
}
