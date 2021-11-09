/*
** EPITECH PROJECT, 2019
** pop
** File description:
** delete peek in stack
*/

#include "new.h"
#include <stdlib.h>

char pop(stack_t **head)
{
    stack_t *node;
    char previous_data = (*head)->data;

    if (*head == NULL) {
        exit(1);
    }
    else {
        node = *head;
        *head = (*head)->next;
        free(node);
    }
    return previous_data;
}
