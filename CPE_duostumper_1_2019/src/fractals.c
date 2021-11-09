/*
** EPITECH PROJECT, 2020
** Duo stumper
** File description:
** fractals
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "my.h"
#include "word_array.h"
#include "fractals.h"

static bool error_fractals(char **chain1, char **chain2)
{
    char *error_char = "Line must have the same number of character\n";
    char *error_nbr = "The chain must have the same number of line break\n";

    if (word_array_len(chain1) == word_array_len(chain2)) {
        for (size_t i = 0; chain1[i] != NULL; i++)
            if (my_strlen(chain1[i]) != my_strlen(chain2[i])) {
                my_putstr_error(error_char);
                return true;
            }
    } else {
        my_putstr_error(error_nbr);
        return true;
    }
    return false;
}

static int error_handling(char **chain1, char **chain2)
{
    if (chain1 == NULL) {
        if (chain2 != NULL)
            free_2d_array(chain2);
        return 84;
    }
    if (chain2 == NULL) {
        if (chain1 != NULL)
            free_2d_array(chain1);
        return 84;
    }
    if (error_fractals(chain1, chain2)) {
        free_2d_array(chain1);
        free_2d_array(chain2);
        return 84;
    }
    return 0;
}

static char ***stock_chains(char **chain1, char **chain2)
{
    char ***chains = malloc(sizeof(char **) * 3);

    chains[0] = chain1;
    chains[1] = chain2;
    chains[2] = NULL;
    return chains;
}

static void free_all_stuff(char **chain1, char **chain2, char ***chains)
{
    free_2d_array(chain1);
    free_2d_array(chain2);
    free(chains);
}

int fractals(char **argv)
{
    char **chain1 = my_str_to_word_array(argv[2], "@");
    char **chain2 = my_str_to_word_array(argv[3], "@");
    char ***chains = stock_chains(chain1, chain2);
    char **result = NULL;
    int scale = my_getnbr(argv[1]);

    if (error_handling(chain1, chain2))
        return 84;
    if (scale == 0) {
        free_all_stuff(chain1, chain2, chains);
        my_putstr("#\n");
        return -1;
    }
    result = fractal_gen(0, scale, chains);
    for (size_t i = 0; result[i] != NULL; i++) {
        my_putstr(result[i]);
        my_putstr("\n");
    }
    free_all_stuff(chain1, chain2, chains);
    return 0;
}
