/*
** EPITECH PROJECT, 2020
** display player 
** File description:
** 
*/

#include <stdlib.h>
#include <math.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my.h"
#include "my_runner.h"

int display_player_atk(game_t *game)
{
    int xoff = 0;
    int size_diff = P_ATK[P_ATKID]->sprite_rect.width
    - PLAYER->sprite_rect.width;
    if (P_STATUS != atk)
        return 0;
    if (PLAYER->facing == RIGHT) {
        sfSprite_setScale(P_ATK[P_ATKID]->spr[P_ATK[P_ATKID]->frame],
        vec2f(-1, 1));
        xoff = PLAYER->sprite_rect.width;
        size_diff = -size_diff;
    } else
        sfSprite_setScale(P_ATK[P_ATKID]->spr[P_ATK[P_ATKID]->frame],
        vec2f(1, 1));
    draw_sprite(game, P_ATK[P_ATKID]->spr[P_ATK[P_ATKID]->frame],
    vec2f(VMODE.width / 2 + xoff - PLAYER->sprite_rect.width / 2
    - size_diff, VMODE.height - (VMODE.height - P_POS.y)));
    return 0;
}

int display_player_setcolor(game_t *game)
{
    if (MSEC(TIME) - MSEC(PLAYER->dmg_time) <= 400 && P_STATUS != dying)
        sfSprite_setColor(SPR->player[P_STATUS][P_FRAME], P_DMG_COLOR);
    else
        sfSprite_setColor(SPR->player[P_STATUS][P_FRAME], RESET_COLOR);
    return 0;
}

int display_player(game_t *game)
{
    int xoff = 0;
    if (PLAYER->facing == RIGHT) {
        sfSprite_setScale(SPR->player[P_STATUS][P_FRAME], vec2f(-1, 1));
        xoff = P_SWIDTH;
    } else
        sfSprite_setScale(SPR->player[P_STATUS][P_FRAME], vec2f(1, 1));
    display_player_setcolor(game);
    draw_sprite(game, SPR->player[P_STATUS][P_FRAME],
    vec2f(VMODE.width / 2 + xoff - PLAYER->sprite_rect.width / 2,
    VMODE.height - (VMODE.height - P_POS.y)));
    return 0;
}
