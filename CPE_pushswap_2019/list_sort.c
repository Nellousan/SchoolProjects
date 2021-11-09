/*
** EPITECH PROJECT, 2019
** list sorting
** File description:
** 
*/

#include "my.h"
#include "push_swap.h"
#include <stdlib.h>
#include <stddef.h>

int is_sorted(list_t *list)
{
    list_t *pg;
     while (list->is_start != -1) {
        pg = list->next;
        if (list->val > pg->val)
            return 0;
        list = list->next;
    }
    return 1;
}

void sort_loop(list_t **start)
{
    list_t *pg;
    while ((*start)->is_start != -1) {
        pg = (*start)->next;
        if ((*start)->val > pg->val)
            swap(start);
        rotate(start);
    }
    rotate(start);
    return;
}
