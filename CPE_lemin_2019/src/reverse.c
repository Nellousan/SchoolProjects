/*
** EPITECH PROJECT, 2020
** Lem-in
** File description:
** Reverse
*/

#include "my.h"
#include "a_malloc.h"
#include "lemin.h"

static char **reverse_tab(char **tab)
{
    size_t i = 0;
    size_t y = 0;
    size_t j = 0;
    char **cp_tab;

    for (y = 0; tab[y] != NULL; y++);
    cp_tab = a_malloc(sizeof(char *) * (y + 1) | A_LIST(1));
    for (j = y - 1; j != -1; i++, j--) {
        cp_tab[i] = tab[j];
    }
    cp_tab[i] = NULL;
    return cp_tab;
}

char ***reverse_all_tab(int nb_links, char ***tab)
{
    for (size_t i = 0; i < (size_t)nb_links; i++)
        tab[i] = reverse_tab(tab[i]);
    return tab;
}
