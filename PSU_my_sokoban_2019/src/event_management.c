/*
** EPITECH PROJECT, 2019
** event managament
** File description:
** 
*/

#include <stdlib.h>
#include <curses.h>
#include "my.h"
#include "my_sokoban.h"

void event_management(game_t *game)
{
    int ch = getch();
    switch (ch) {
    case ' ':
        game_reload(game);
        break;
    case KEY_UP:
        player_move(game, POS_UP(P_POS));
        break;
    case KEY_DOWN:
        player_move(game, POS_DOWN(P_POS));
        break;
    case KEY_LEFT:
        player_move(game, POS_LEFT(P_POS));
        break;
    case KEY_RIGHT:
        player_move(game, POS_RIGHT(P_POS));
        break;
    }
    return;
}
