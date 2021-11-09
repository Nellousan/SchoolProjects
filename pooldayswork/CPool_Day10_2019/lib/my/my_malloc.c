/*
** EPITECH PROJECT, 2019
** my malloc
** File description:
** 
*/

#include <stdlib.h>

int my_malloc(int type_size, int amount, int p)
{
    return malloc(type_size * (amount + p));
}
