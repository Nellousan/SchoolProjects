/*
** EPITECH PROJECT, 2020
** display_enemies
** File description:
** Obiwan Kenobi
*/

#include "defender.h"

void display_enemies(game_t *game)
{
    static sfTime frame_ch = {0};
    static int frame = 0;
    if (GETMS(TIME) - GETMS(frame_ch) > 500) {
        frame = (frame == 1) ? 0 : 1;
        frame_ch = TIME;
    }
    for (int i = 0; i < 15; i++) {
        if (MOB[i].obj_status == 1) {
            sfSprite_setPosition(SPR->mob[0][frame], MOB[i].pos);
            sfRenderWindow_drawSprite(game->window, SPR->mob[0][frame], NULL);
        }
    }
}
