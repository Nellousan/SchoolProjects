/*
** EPITECH PROJECT, 2019
** player data update
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

int player_frame_update(game_t *game)
{
    if (MSEC(TIME) - MSEC(PLAYER->frame_time) < P_ANIMD[P_STATUS]->frame_spd)
        return 0;
    P_FRAME++;
    if (P_FRAME >= P_ANIMD[P_STATUS]->framecount) {
        if (P_ANIMD[P_STATUS]->loop == 1)
            P_FRAME = P_ANIMD[P_STATUS]->loop_frame;
        else
            P_FRAME--;
    }
    P_ATK[P_ATKID]->frame++;
    if (P_ATK[P_ATKID]->frame >= P_ATK[P_ATKID]->anim_data->framecount) {
        if (P_ATK[P_ATKID]->anim_data->loop == 1)
            P_ATK[P_ATKID]->frame = P_ATK[P_ATKID]->anim_data->loop_frame;
        else
            P_ATK[P_ATKID]->frame--;
    }
    PLAYER->frame_time = sfClock_getElapsedTime(CLOCK);
    return 0;
}

int player_status_update(game_t *game)
{
    if (can_player_fall(game) && P_STATUS != fall && P_STATUS != atk) {
        P_STATUS = fall;
        P_FRAME = 0;
    }
    if (P_STATUS == fall && !can_player_fall(game)) {
        P_STATUS = idle;
        P_FRAME = 0;
    }
    if (P_STATUS == rise && MSEC(TIME) - MSEC(PLAYER->squat_time) >=
    (PLAYER->jump_h * 1000) / PLAYER->jump_spd) {
        P_STATUS = fall;
        P_FRAME = 0;
    }
    return 0;
}

int player_data_update(game_t *game)
{
    player_hit_management(game);
    player_frame_update(game);
    if (MSEC(TIME) - MSEC(PLAYER->atk_time) > PLAYER->atk_cd)
        player_status_update(game);
    player_key_press_update(game);
    player_pos_update(game);
    player_height_update(game);
    return 0;
}
