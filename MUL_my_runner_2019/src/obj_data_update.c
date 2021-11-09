/*
** EPITECH PROJECT, 2020
** object data update
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

int obj_hit_management(game_t *game, obj_t *obj)
{
    if (obj->e_status != o_dying && MSEC(TIME) - MSEC(obj->dmg_time) > 150) {
        obj->hp -= P_ATK[P_ATKID]->damage;
        obj->dmg_time = sfClock_getElapsedTime(CLOCK);
    }
    return 0;
}

int obj_status_update(game_t *game, obj_t *obj)
{
    if (obj->obj_status != 1)
        return 0;
    if (obj->hp <= 0 && obj->e_status != o_dying) {
        obj->e_status = o_dying;
        obj->frame = 0;
        obj->status_time = sfClock_getElapsedTime(CLOCK);
    }
    if (obj->e_status == o_dying && obj->frame >=
        E_LIST[obj->id]->anim_data[o_dying]->framecount - 1)
        obj->obj_status = 0;
    return 0;
}

int obj_frame_update(game_t *game, obj_t *obj)
{
    if (obj->obj_status != 1)
        return 0;
    if (MSEC(TIME) - MSEC(obj->frame_time) > OBJ_ANIMD[OBJ_STATUS]->frame_spd) {
        OBJ_FRAME++;
        obj->frame_time = sfClock_getElapsedTime(CLOCK);
    }
    if (OBJ_FRAME >= OBJ_ANIMD[OBJ_STATUS]->framecount) {
        if (OBJ_ANIMD[OBJ_STATUS]->loop == 1)
            OBJ_FRAME = OBJ_ANIMD[OBJ_STATUS]->loop_frame;
        else
            OBJ_FRAME--;
    }
    return 0;
}

int obj_data_update(game_t *game)
{
    for (int i = 0; i < 32; i++) {
        obj_status_update(game, OBJ[i]);
        obj_frame_update(game, OBJ[i]);
        obj_behaviour_selector(game, OBJ[i]);
    }
    return 0;
}
