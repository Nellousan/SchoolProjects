/*
** EPITECH PROJECT, 2020
** main
** File description:
** c
*/

#include <stdbool.h>
#include <curses.h>
#include "tetris.h"
#include "a_malloc.h"

int main(int argc, char **argv)
{
    game_t *game = game_load(argc, argv);
    initscr();
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    if (DBG)
        debug(game);
    game_loop(game);
    endwin();
    a_malloc(A_MALLOC_FREE);
    a_malloc(A_MALLOC_FREE | A_LIST(1));
    return 0;
}
