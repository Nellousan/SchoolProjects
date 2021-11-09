/*
** EPITECH PROJECT, 2019
** my list size
** File description:
** return size of linked list 
*/

#include "my.h"
#include "mylist.h"
#include <stdlib.h>

int my_list_size(linked_list_t const *begin)
{
    linked_list_t *tmp;
    int i = 0;

    tmp = (linked_list_t *)begin;
    for (i = 0; tmp != NULL; i++) {
        tmp = tmp->next;
    }
    return i;
}
