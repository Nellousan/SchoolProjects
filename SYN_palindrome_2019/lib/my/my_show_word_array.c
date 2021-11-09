/*
** EPITECH PROJECT, 2019
** my_show_word_array
** File description:
** display words of array
*/

#include <stddef.h>

int my_putstr(char *str);

int my_show_word_array(char * const *tab)
{
    for (size_t i = 0; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
        my_putstr("\n");
    }
}
