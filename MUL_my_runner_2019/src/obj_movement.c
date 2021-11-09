/*
** EPITECH PROJECT, 2020
** obj movement
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

int can_obj_move(game_t * game, obj_t *obj, sfVector2f pos)
{
    sfIntRect hurtbox = rect(pos.x + obj->hurtbox.left, pos.y +
    obj->hurtbox.top, obj->hurtbox.width, obj->hurtbox.height);
    for (int i = 0; O_MAP[i] != NULL; i++)
        if (rect_collide_check(hurtbox, O_MAP[i]->rect))
            return 0;
    return 1;
}

int can_obj_fall(game_t *game, obj_t *obj)
{
    int i = 0;
    for (i = 0; i <= 20; i++)
        if (!can_obj_move(game, obj, vec2f(obj->pos.x, obj->pos.y + i))) {
            obj->pos.y += i - 1;
            return 0;
        }
    return 1;
}

int obj_move(game_t *game, obj_t *obj, sfVector2f pos)
{
    if (can_obj_move(game, obj, pos)) {
        obj->pos = pos;
        return 1;
    }
    return 0;
}
