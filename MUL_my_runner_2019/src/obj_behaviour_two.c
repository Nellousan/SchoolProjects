/*
** EPITECH PROJECT, 2020
** behaviour 2
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

int bhv_two_facing_update(game_t *game, obj_t *obj)
{
    if (obj->pos.x >= P_POS.x)
        obj->facing = LEFT;
    else if (obj->pos.x < P_POS.x)
        obj->facing = RIGHT;
    return 0;
}

int bhv_two_pos_update(game_t *game, obj_t *obj)
{
    if (obj->facing == LEFT)
        obj_move(game, obj, vec2f(obj->pos.x - (float)(MSEC(TIME) -
        MSEC(obj->pos_time)) * obj->run_spd / 1000, obj->pos.y));
    else if (obj->facing == RIGHT) {
        obj_move(game, obj, vec2f(obj->pos.x + (float)(MSEC(TIME) -
        MSEC(obj->pos_time)) * obj->run_spd / 1000, obj->pos.y));
    }
    obj->pos_time = sfClock_getElapsedTime(CLOCK);
    return 0;
}

int bhv_two_height_update(game_t *game, obj_t *obj)
{
    if (can_obj_fall(game, obj)) {
        obj_move(game, obj, vec2f(obj->pos.x, obj->pos.y + (float)(MSEC(TIME) -
        MSEC(obj->pos_time)) * 400 / 1000));
    }
    return 0;
}

int behaviour_two_management(game_t *game, obj_t *obj)
{
    if (obj->e_status == o_dying)
        return 0;
    bhv_two_facing_update(game, obj);
    bhv_two_height_update(game, obj);
    bhv_two_pos_update(game, obj);
    return 0;
}
