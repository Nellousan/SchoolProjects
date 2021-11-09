/*
** EPITECH PROJECT, 2020
** Lem-in
** File description:
** Init
*/

#include "my.h"
#include "lemin.h"

int *init_tab_int(int nb_max)
{
    int *tab = malloc(sizeof(int) * nb_max);

    for (size_t y = 0; y < (size_t)nb_max; y++)
        tab[y] = 0;
    return tab;
}

result_t init_result(int id, int nb)
{
    result_t result;
    result.id = id;
    result.result = nb;
    return result;
}

result_t *init_tab_result(int nb, int node_max)
{
    result_t *tab = malloc(sizeof(result_t) * node_max);

    for (size_t i = 0; i < (size_t)node_max; i++)
        tab[i] = init_result(i, nb);
    return tab;
}

char ***init_tab_char(int max, int node_max)
{
    size_t i = 0;
    size_t y = 0;
    char ***tab = malloc(sizeof(char **) * max);

    for (i = 0; i < (size_t)max; i++) {
        tab[i] = malloc(sizeof(char *) * node_max + 1);
        for (y = 0; y < (size_t)node_max; y++)
            tab[i][y] = malloc(sizeof(char) * 2048);
    }
    for (i = 0; i < (size_t)max; i++)
        for (y = 0; y < (size_t)node_max; y++)
            tab[i][y] = NULL;
    tab[i - 1][y] = NULL;
    return tab;
}

void init_all(int node_max, int **from, lemin_t *lemin)
{
    I = START;
    (*from) = init_tab_int(node_max);
    RES = init_tab_result(1000000, node_max);
    SOLUT = init_tab_char(NODE[START]->nb_links, node_max);
}
