/*
** EPITECH PROJECT, 2019
** my_rev_list
** File description:
** reverse list
*/

#include "my.h"
#include "mylist.h"
#include <stdlib.h>

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *tmp_next = (*begin)->next;
    linked_list_t *tmp_prev = NULL;
    while ((*begin)->next != NULL) {
        tmp_next = (*begin)->next;
        (*begin)->next = tmp_prev;
        tmp_prev = (*begin);
        (*begin) = tmp_next;
    }
    (*begin)->next = tmp_prev;
}
