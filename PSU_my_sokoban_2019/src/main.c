/*
** EPITECH PROJECT, 2019
** main
** File description:
** 
*/

#include <stdlib.h>
#include <curses.h>
#include "my.h"
#include "my_sokoban.h"

int main(int argc, char **argv)
{
    int return_status;
    if (argc < 2)
        return 84;
    game_t *game = game_load(argv[1]);
    if (game == NULL)
        return 84;
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    game_loop(game);
    return_status = get_return_status(game);
    game_unload(game);
    endwin();
    return return_status;
}
