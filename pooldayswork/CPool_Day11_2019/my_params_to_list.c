/*
** EPITECH PROJECT, 2019
** my_param_to_list
** File description:
** explicit name
*/

#include "my.h"
#include "mylist.h"
#include <stdlib.h>

int my_put_params_list(linked_list_t **list, char *str)
{
    linked_list_t *param_list;

    param_list = malloc(sizeof(linked_list_t));
    param_list->data = str;
    param_list->next = *list;
    *list = param_list;
    return 0;
}

void my_show_params_list(linked_list_t *list)
{
    linked_list_t *tmp;

    tmp = list;
    while (tmp != NULL) {
        my_putstr(tmp->data);
        my_putchar('\n');
        tmp = tmp->next;
    }
}

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *list = NULL;
    
    for (int i = 0; av[i] != NULL; i++) {
        my_put_params_list(&list, av[i]);
    }
    return list;
}
