/*
** EPITECH PROJECT, 2019
** list creation funcs
** File description:
** 
*/

#include "my.h"
#include "push_swap.h"
#include <stdlib.h>
#include <stddef.h>

list_t *list_create(int val, void *prev, void *next)
{
    list_t *list = malloc(sizeof(list_t));
    list->val = val;
    list->prev = prev;
    list->next = next;
    return list;
}

//return beginning of list
list_t *argv_to_list(int argc, char **argv)
{
    list_t *start = list_create(char_to_int(my_strdup(argv[1])), NULL, NULL);
    list_t *current = start;
    for (int i = 2; i < argc; i++) {
        current->next = list_create(char_to_int(my_strdup(argv[i])),
                                    current, NULL);
        current->is_start = 0;
        current = current->next;
    }
    current->is_start = -1;
    current->next = start;
    start->is_start = 1;
    return start;
}
