/*
** EPITECH PROJECT, 2019
** peek
** File description:
** peek in stack
*/

#include "new.h"
#include <stdbool.h>

bool is_empty(stack_t *head);

char peek(stack_t *head)
{
    if (is_empty(head) == false)
        return head->data;
    else {
        return 0;
    }
}
