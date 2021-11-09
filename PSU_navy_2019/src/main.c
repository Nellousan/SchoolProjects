/*
** EPITECH PROJECT, 2020
** main
** File description:
** navy
*/

#include <stddef.h>
#include "my.h"
#include "navy.h"
#include "a_malloc.h"

int GET_HITPOS = 0;

int main(int argc, char **argv)
{
    game_t *game;
    if (argc < 2)
        return 84;
    game = game_load(argc, argv);
    if (game == NULL)
        return 84;
    establish_connection(game);
    game_loop(game);
    a_malloc(A_MALLOC_FREE);
    a_malloc(A_MALLOC_FREE | A_LIST(1));
    return RETURN_STATUS;
}
