/*
** EPITECH PROJECT, 2020
** player pos update
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

int player_height_update(game_t *game)
{
    if (P_STATUS == rise) {
        player_move(game, vec2f(P_POS.x, P_POS.y - (float)(MSEC(TIME) -
        MSEC(PLAYER->pos_time)) * PLAYER->jump_spd / 1000));
    }
    else if (P_STATUS == fall || (P_STATUS == atk && can_player_fall(game))) {
        player_move(game, vec2f(P_POS.x, P_POS.y + (float)(MSEC(TIME) -
        MSEC(PLAYER->pos_time)) * PLAYER->jump_spd / 1000));
    }
    PLAYER->pos_time = sfClock_getElapsedTime(CLOCK);
    return 0;
}

int player_move_dmg(game_t *game)
{
    player_move(game, vec2f(P_POS.x - (float)(MSEC(TIME) -
    MSEC(PLAYER->pos_time)) * PLAYER->run_spd / 1000, P_POS.y));
    return 0;
}

int player_pos_update(game_t *game)
{
    if (MSEC(TIME) - MSEC(PLAYER->dmg_time) < 200 && MSEC(TIME) > 200) {
        player_move_dmg(game);
        return 0;
    } if (P_STATUS == run || P_STATUS == rise || P_STATUS == fall) {
        if (PLAYER->facing == RIGHT && sfKeyboard_isKeyPressed(KEY[1]->code))
            player_move(game, vec2f(P_POS.x + (float)(MSEC(TIME) -
            MSEC(PLAYER->pos_time)) * PLAYER->run_spd / 1000, P_POS.y));
        else if (PLAYER->facing == LEFT &&
            sfKeyboard_isKeyPressed(KEY[0]->code))
            player_move(game, vec2f(P_POS.x - (float)(MSEC(TIME) -
            MSEC(PLAYER->pos_time)) * PLAYER->run_spd / 1000, P_POS.y));
    } if (P_STATUS == atk && can_player_fall(game)) {
        if (sfKeyboard_isKeyPressed(KEY[1]->code))
            player_move(game, vec2f(P_POS.x + (float)(MSEC(TIME) -
            MSEC(PLAYER->pos_time)) * (PLAYER->run_spd / 2) / 1000, P_POS.y));
        else if (sfKeyboard_isKeyPressed(KEY[0]->code))
            player_move(game, vec2f(P_POS.x - (float)(MSEC(TIME) -
            MSEC(PLAYER->pos_time)) * (PLAYER->run_spd / 2) / 1000, P_POS.y));
    }
    return 0;
}
