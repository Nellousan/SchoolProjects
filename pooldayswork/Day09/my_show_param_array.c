/*
** EPITECH PROJECT, 2019
** my_show_param_array
** File description:
** displays structure of param
*/

#include <stdlib.h>
#include "my.h"

int my_show_param_array(struct info_param const *par)
{
    for (int i = 0; par[i].str != NULL; i++) {
        my_put_nbr(par[i].length);
        my_putstr("\n");
        my_putstr(par[i].copy);
        my_putstr("\n");
        my_show_word_array(par[i].word_array);
        my_putstr("\n");
    }
}
