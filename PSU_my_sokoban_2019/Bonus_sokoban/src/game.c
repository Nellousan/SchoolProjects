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
    WINDOW = sfRenderWindow_create(VMODE, "Sokoban", sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(WINDOW, 60);
    while (!is_game_over(game) && sfRenderWindow_isOpen(WINDOW)) {
        sf_display_management(game);
        display_management(game);
        event_management(game);
        box_status_refresh(game);
    }
    return;
}
