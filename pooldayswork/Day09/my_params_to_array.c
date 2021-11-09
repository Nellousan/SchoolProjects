/*
** EPITECH PROJECT, 2019
** my_params_to_array
** File description:
** param into struct array
*/

#include "my.h"
#include <stdlib.h>

struct info_param *my_params_to_array(int ac, char **av)
{
    int i = 0;
    struct info_param *param_struct = malloc(sizeof(struct info_param) * (ac + 1));
    for (i = 0; i < ac; i++) {
        param_struct[i].length = my_strlen(av[i]);
        param_struct[i].str = av[i];
        param_struct[i].copy = my_strdup(av[i]);
        param_struct[i].word_array = my_str_to_word_array(av[i]);
    }
    param_struct[i + 1].str = NULL;
    return param_struct;
}
