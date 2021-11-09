/*
** EPITECH PROJECT, 2019
** game unload
** File description:
** 
*/

#include <stdlib.h>
#include <curses.h>
#include "my.h"
#include "my_sokoban.h"

void game_unload(game_t *game)
{
    free(game->map_path);
    free(BOX);
    free(DRAW_MAP);
    free(SLOTS);
    free(MAP);
    free(GOALS);
    free(game);
    return;
}
