/*
** EPITECH PROJECT, 2020
** display
** File description:
** management
*/

#include <curses.h>
#include <stdbool.h>
#include "tetris.h"

void display_management(game_t *game)
{
    erase();
    display_board(game);
    wrefresh(stdscr);
    return;
}
