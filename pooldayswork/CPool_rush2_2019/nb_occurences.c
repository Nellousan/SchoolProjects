/*
** EPITECH PROJECT, 2019
** nb_occurences.c
** File description:
** compte le nombre d'occurences
*/

#include "lib/my/my.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int my_char_isalpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    else
        return 0;
}

int nb_occurence(char const *str, char c)
{
    int i = 0;
    int counter = 0;

    while (str[i] != '\0') {
        if (str[i] == c) {
            counter++;
            i++;
        }
        else
            i++;
    }
        return counter;
}

void *print(int ac, char **av)
{
    int i = 2;

    while (i < ac && ac > 1) {
        if (my_char_isalpha(av[i][0]) == 0)
            i++;
        else if (my_char_isalpha(av[i][0]) == 1) {
            my_putchar(av[i][0]);
            my_putchar(':');
            my_putnbr(nb_occurence(av[1], av[i][0]));
            my_putchar(' ');
            put_freq(nb_occurence(av[1], av[i][0]), count_letters(av[1]));
            i++;
        }
    }
    return 0;
}

int main (int ac, char **av)
{
    print(ac, av);
    return 0;
}
