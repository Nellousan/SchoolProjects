/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** a
*/

#include "stumper.h"
#include "a_malloc.h"

int main(int argc, char **argv)
{
    game_t *game = game_load(argc, argv);
    if (!game)
        return 84;
    game_loop(game);
    a_malloc(A_MALLOC_FREE | A_LIST(1));
    a_malloc(A_MALLOC_FREE);
    return 0;
}
