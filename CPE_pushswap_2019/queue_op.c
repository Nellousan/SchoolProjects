/*
** EPITECH PROJECT, 2019
** queue operations
** File description:
** 
*/

#include "my.h"
#include "push_swap.h"
#include <stdlib.h>
#include <stddef.h>

void change_end(list_t *start)
{
    list_t *pg = start;
    while (pg->is_start != -1)
        pg = pg->next;
    pg->next = start;
    return;
}

list_t *get_prev(list_t *list)
{
    list_t *pg = list;
    while (pg->next != list) {
        pg = pg->next;
    }
    return pg;
}

void swap(list_t **start)
{
    list_t *pg = (*start);
    list_t *prev = get_prev((*start));
    int temp;
    if ((*start)->is_start == 1)
        change_end((*start)->next);
    (*start) = (*start)->next;
    pg->next = (*start)->next;
    (*start)->next = pg;
    temp = (*start)->is_start;
    (*start)->is_start = pg->is_start;
    pg->is_start = temp;
    prev->next = (*start);
    my_putstr("sa ");
    return;
}

void rotate(list_t **start)
{
    (*start) = (*start)->next;
    my_putstr("ra ");
    return;
}
