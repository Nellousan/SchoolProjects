/*
** EPITECH PROJECT, 2019
** keypress
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

void no_key(game_t *game)
{
    if (P_STATUS != idle && !can_player_fall(game) && P_STATUS != rise) {
        PLAYER->frame = 0;
        PLAYER->frame_time = sfClock_getElapsedTime(CLOCK);
        PLAYER->status_time = sfClock_getElapsedTime(CLOCK);
    }
    if (!IS_AIRBORN(game) || (P_STATUS == fall &&
        !can_player_move(game, vec2f(P_POS.x, P_POS.y + 1))))
        P_STATUS = idle;
    return;
}

void key_left(game_t *game)
{
    if (P_STATUS != run && !sfKeyboard_isKeyPressed(KEY[2]->code)
    && !can_player_fall(game) && P_STATUS != rise) {
        PLAYER->frame = 0;
        PLAYER->frame_time = sfClock_getElapsedTime(CLOCK);
        PLAYER->status_time = sfClock_getElapsedTime(CLOCK);
        P_STATUS = run;
    }
    PLAYER->facing = LEFT;
    return;
}

void key_right(game_t *game)
{
    if (P_STATUS != run && !sfKeyboard_isKeyPressed(KEY[2]->code)
    && !can_player_fall(game) && P_STATUS != rise) {
        PLAYER->frame = 0;
        PLAYER->frame_time = sfClock_getElapsedTime(CLOCK);
        PLAYER->status_time = sfClock_getElapsedTime(CLOCK);
        P_STATUS = run;
    }
    PLAYER->facing = RIGHT;
    return;
}

void key_down(game_t *game)
{
    if (P_STATUS != crouch && !can_player_fall(game) && P_STATUS != rise) {
        PLAYER->frame = 0;
        PLAYER->frame_time = sfClock_getElapsedTime(CLOCK);
        PLAYER->status_time = sfClock_getElapsedTime(CLOCK);
        P_STATUS = crouch;
    }
    return;
}
