/*
** EPITECH PROJECT, 2020
** player movement functions
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

void jump_management(game_t *game)
{
    if (P_STATUS != fall && P_STATUS != rise) {
        P_STATUS = rise;
        P_FRAME = 0;
        PLAYER->air_momentum = PLAYER->jump_spd;
        PLAYER->squat_time = sfClock_getElapsedTime(CLOCK);
    }
    return;
}

int can_player_move(game_t *game, sfVector2f pos)
{
    sfIntRect hurtrect = rect(pos.x + P_HURT.left, pos.y +
    P_HURT.top, P_HURT.width, P_HURT.height);
    for (int i = 0; O_MAP[i] != NULL; i++) {
        if (O_MAP[i]->type == 2 && rect_collide_check(hurtrect, O_MAP[i]->rect))
            G_STATUS = end;
        if (rect_collide_check(hurtrect, O_MAP[i]->rect))
            return 0;
    }
    return 1;
}

int can_player_fall(game_t *game)
{
    int i = 0;
    if (P_STATUS == rise)
        return 0;
    for (i = 1; i <= 20; i++) {
        if (!can_player_move(game, vec2f(P_POS.x, P_POS.y + i))) {
            P_POS.y += i - 1;
            return 0;
        }
    }
    return 1;
}

int player_move(game_t *game, sfVector2f pos)
{
    if (can_player_move(game, pos)) {
        P_POS = pos;
        return 1;
    }
    return 0;
}
