/*
** EPITECH PROJECT, 2020
** main duo stumper 1
** File description:
** main.c
*/

#include "my.h"
#include "fractals.h"
#include "a_malloc.h"

int main(int argc, char **argv)
{
    int ret = 0;

    if (!syntax_check(argc, argv))
        return 84;
    ret = fractals(argv);
    if (ret == -1)
        return 0;
    a_malloc(A_MALLOC_FREE);
    return ret;
}
