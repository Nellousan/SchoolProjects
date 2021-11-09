/*
** EPITECH PROJECT, 2019
** game loop
** File description:
** 
*/

#include <stdlib.h>
#include <curses.h>
#include "my.h"
#include "my_sokoban.h"

void game_loop(game_t *game)
{
    display_management(game);
    while (!is_game_over(game)) {
        event_management(game);
        display_management(game);
        box_status_refresh(game);
    }
    return;
}
