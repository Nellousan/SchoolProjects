/*
** EPITECH PROJECT, 2020
** player attack management
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

int player_attack_hit_management(game_t *game)
{
    int offset = -PLAYER->sprite_rect.width / 2;
    sfIntRect hitbox = rect(P_ATK[P_ATKID]->hitbox.left + P_POS.x - P_SWIDTH
    / 2, P_ATK[P_ATKID]->hitbox.top + P_POS.y, P_ATK[P_ATKID]->hitbox.width,
    P_ATK[P_ATKID]->hitbox.height);
    if (P_ATK[P_ATKID]->lingering_time < MSEC(TIME) - MSEC(PLAYER->atk_time))
        return 0;
    if (PLAYER->facing == LEFT)
        offset = -offset;
    for (int i = 0; i < 32; i++) {
        if (OBJ[i]->obj_status == 1 && rect_collide_check(hitbox, rect(
            OBJ[i]->hurtbox.left + OBJ[i]->pos.x + offset - P_SWIDTH / 2,
            OBJ[i]->hurtbox.top +
            OBJ[i]->pos.y, OBJ[i]->hurtbox.width, OBJ[i]->hurtbox.height)))
            obj_hit_management(game, OBJ[i]);
    }
    return 0;
}

int player_attack_management(game_t *game, p_atk_t *p_atk)
{
    if (P_STATUS != atk && MSEC(TIME) - MSEC(PLAYER->atk_time) >
    PLAYER->atk_cd) {
        P_STATUS = atk;
        P_FRAME = 0;
        p_atk->frame = 0;
        PLAYER->atk_time = sfClock_getElapsedTime(CLOCK);
        PLAYER->atk_cd = p_atk->cooldown;
    }
    return 0;
}
