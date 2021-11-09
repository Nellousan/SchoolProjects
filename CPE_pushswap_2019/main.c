/*
** EPITECH PROJECT, 2019
** main
** File description:
** 
*/

#include "my.h"
#include "push_swap.h"
#include <stdlib.h>
#include <stddef.h>

int main(int argc, char **argv)
{
    list_t *start = argv_to_list(argc, argv);
    while (!is_sorted(start)) {
        sort_loop(&start);
    }
    my_putchar('\n');
    return 0;
}

