/*
** EPITECH PROJECT, 2020
** display
** File description:
** board
*/

#include <curses.h>
#include <stdbool.h>
#include "tetris.h"

static void display_line(vect_t v, int s)
{
    int i = 0;
    mvwaddch(stdscr, v.y, v.x - 1, '+');
    for (i = 0; i < s; i++) {
        mvwaddch(stdscr, v.y, v.x + i, '-');
    }
    mvwaddch(stdscr, v.y, v.x + i, '+');
    return;
}

static void display_mapn_line(game_t *game, int i)
{
    int j = 0;
    for (j = 0; j < MAP_SIZE.x; j++) {
        mvwaddch(stdscr, i + 1, XOFF + j, MAPN[i][j]->c);
    }
    return;
}

void display_board(game_t *game)
{
    int i = 0;
    display_line(VECT(XOFF, 0), MAP_SIZE.x);
    for (i = 0; i < MAP_SIZE.y; i++) {
        mvwaddch(stdscr, i + 1, XOFF - 1, '|');
        display_mapn_line(game, i);
        mvwaddch(stdscr, i + 1, XOFF + MAP_SIZE.x, '|');
    }
    display_line(VECT(XOFF, MAP_SIZE.y + 1), MAP_SIZE.x);
    return;
}
