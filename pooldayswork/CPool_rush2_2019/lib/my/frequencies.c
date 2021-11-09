/*
** EPITECH PROJECT, 2019
** frequencies
** File description:
** calculate frequencies of letters in sentence
*/

#include <stddef.h>

void my_putstr(char *str);

int my_putpercent(int nb);

int put_freq(int counter, int nb_letter)
{
    my_putstr("(");
    my_putpercent(10000 * counter / nb_letter);
    my_putstr("%)\n");
    return (10000 * counter / nb_letter);
}
