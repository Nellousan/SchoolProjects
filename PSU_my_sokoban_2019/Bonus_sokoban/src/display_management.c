/*
** EPITECH PROJECT, 2019
** display management
** File description:
** 
*/

#include <stdlib.h>
#include <curses.h>
#include "my.h"
#include "my_sokoban.h"

void print_walls(game_t *game)
{
    int j = 0;
    int i = 0;
    for (; MAP->draw_map[i] != '\0'; i++, j++) {
        if (MAP->draw_map[i] == '\n')
            i++;
        if (MAP->draw_map[i] == '#') {
            wmove(stdscr, j / MWIDTH, j % MWIDTH);
            waddch(stdscr, '#');
        } else if (MAP->draw_map[i] == 'O') {
            wmove(stdscr, j / MWIDTH, j % MWIDTH);
            waddch(stdscr, 'O');
        }
    }
    return;
}

void print_boxes(game_t *game)
{
    for (int i = 0; i < game->box_count; i++) {
            wmove(stdscr, BOX[i].pos.y, BOX[i].pos.x);
            waddch(stdscr, 'X');
    }
    return;
}

void print_player(game_t *game)
{
    wmove(stdscr, PLAYER_Y, PLAYER_X);
    waddch(stdscr, 'P');
    return;
}

void print_enlarge(game_t *game)
{
    wmove(stdscr, MAXH / 2, MAXW / 2 - my_strlen(ENLARGE_MSG) / 2);
    printw("%s", ENLARGE_MSG);
    return;
}

void display_management(game_t *game)
{
    erase();
    getmaxyx(stdscr, MAXH, MAXW);
    if (MAXH < MHEIGHT || MAXW < MWIDTH)
        print_enlarge(game);
    else {
    print_walls(game);
    print_boxes(game);
    print_player(game);
    wmove(stdscr, 0, MWIDTH);
    }
    refresh();
    return;
}
