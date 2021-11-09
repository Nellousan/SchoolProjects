/*
** EPITECH PROJECT, 2019
** miscellaneous fuctions
** File description:
** 
*/

#include "my.h"
#include "push_swap.h"
#include <stdlib.h>
#include <stddef.h>

//always send strdup
int char_to_int(char *str)
{
    int neg = 0;
    int nb = 0;
    if (str[0] == '-') {
        str++;
        neg = 1;
    }
    for (int i = 0; str[i] != '\0'; i++)
        nb += DEC(str[i]) * my_pow(10, my_strlen(str) - (i + 1));
    if (neg) {
        nb = -nb;
        str--;
    }
    free(str);
    return nb;
}

void display_list(list_t *start)
{
    list_t *current = start;
    my_putchar('\n');
    do {
        my_putnbr(current->val);my_putchar(' ');my_putnbr(current->is_start);
        my_putchar('\n');
        current = current->next;
    } while (current->is_start != 1);
    my_putnbr(current->val);
    return;
}
