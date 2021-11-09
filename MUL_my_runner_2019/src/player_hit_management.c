/*
** EPITECH PROJECT, 2020
** player hit management
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

int player_hit_update(game_t *game, obj_t *obj)
{
    if (MSEC(TIME) - MSEC(PLAYER->dmg_time) < 400 || obj->e_status == o_dying)
        return 0;
    sfMusic_stop(PLAYER->hitsound);
    sfMusic_play(PLAYER->hitsound);
    PLAYER->hp -= obj->damage;
    PLAYER->dmg_time = sfClock_getElapsedTime(CLOCK);
    return 0;
}

int player_hit_management(game_t *game)
{
    sfIntRect hurtbox = rect(P_HURT.left + P_POS.x - P_SWIDTH / 2, P_HURT.top
    + P_POS.y, P_HURT.width, P_HURT.height);
    for (int i = 0; i < 32; i++) {
        if (OBJ[i]->obj_status == 1 && rect_collide_check(hurtbox, rect(
            OBJ[i]->hitbox.left + OBJ[i]->pos.x -
            P_SWIDTH / 2, OBJ[i]->hitbox.top
            + OBJ[i]->pos.y, OBJ[i]->hitbox.width, OBJ[i]->hitbox.height)))
            player_hit_update(game, OBJ[i]);
    }
    return 0;
}
