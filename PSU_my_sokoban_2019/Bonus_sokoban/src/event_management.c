/*
** EPITECH PROJECT, 2019
** event managament
** File description:
** 
*/

#include <stdlib.h>
#include <curses.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "my_sokoban.h"

void key_press_management(game_t *game, sfKeyEvent event)
{
    switch (event.code) {
    case sfKeySpace:
        break;
    case sfKeyUp:
        player_move(game, POS_UP(P_POS));
        break;
    case sfKeyDown:
        player_move(game, POS_DOWN(P_POS));
        break;
    case sfKeyLeft:
        player_move(game, POS_LEFT(P_POS));
        break;
    case sfKeyRight:
        player_move(game, POS_RIGHT(P_POS));
        break;
    }
    return;
}

void event_management(game_t *game)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(WINDOW, &event)) {
        if (event.type == sfEvtKeyPressed)
            key_press_management(game, event.key);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(WINDOW);
    }
    return;
}
