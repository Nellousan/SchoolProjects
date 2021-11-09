/*
** EPITECH PROJECT, 2019
** push
** File description:
** in stack
*/

#include "new.h"
#include <stdlib.h>

void push(stack_t **head, char x)
{
    stack_t *node = NULL;

    node = malloc(sizeof(stack_t));
    node->data = x;
    node->next = *head;
    *head = node;

}
