/*
** EPITECH PROJECT, 2020
** ant
** File description:
** list
*/

#include "lemin.h"
#include "a_malloc.h"
#include "my.h"

ant_t **ant_list_init(lemin_t *lemin)
{
    ant_t **ant = a_malloc(sizeof(ant_t *) * (lemin->nb_ant + 1) | A_LIST(1));
    int i = 0;
    for (i = 0; i < lemin->nb_ant; i++) {
        ant[i] = a_malloc(sizeof(ant_t) | A_LIST(1));
        ant[i]->id = i + 1;
        ant[i]->pos_id = lemin->start_id;
    }
    return ant;
}
