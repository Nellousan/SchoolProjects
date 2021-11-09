/*
** EPITECH PROJECT, 2020
** game
** File description:
** loop
*/

#include <curses.h>
#include <stdbool.h>
#include "tetris.h"

int game_loop(game_t *game)
{
    init_map(game);
    while (getch() != QUIT_KEY) {
        display_management(game);
    }
    return 0;
}
