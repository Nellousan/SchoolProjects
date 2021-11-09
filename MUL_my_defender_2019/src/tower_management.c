/*
** EPITECH PROJECT, 2020
** tower
** File description:
** management
*/

#include <math.h>
#include "defender.h"

static int is_in_range(o_mob_t *mob, o_tower_t *tw)
{
    sfVector2f nv = SFVEC2F(mob->pos.x - tw->pos.x, mob->pos.y - tw->pos.y);
    float dist = sqrtf(powf(fabsf(nv.x), 2) + powf(fabsf(nv.y), 2));
    if (dist < (float)tw->range)
        return 1;
    return 0;
}

static int tower_focus_update(game_t *game, o_tower_t *tower)
{
    if (tower->focus != -1 && MOB[tower->focus].obj_status != 1) {
        tower->focus = -1;
        return 1;
    }
    for (int i = 0; i < 32; i++) {
        if (MOB[i].obj_status == 1 && is_in_range(&MOB[i], tower)) {
            tower->focus = i;
            return 2;
        }
    }
    return 0;
}

static int tower_frame_update(game_t *game, o_tower_t *tower)
{
    if (GETMS(TIME) - GETMS(tower->frame_ch) > 300) {
        tower->frame = (tower->frame == 0) ? 1 : 0;
        tower->frame_ch = TIME;
    }
    return 0;
}

static int tower_attack_update(game_t *game, o_tower_t *tower)
{
    if (tower->focus == -1)
        return 1;
    if (GETMS(TIME) - GETMS(tower->last_attack) > 1000) {
        MOB[tower->focus].hp -= tower->damage;
        tower->last_attack = TIME;
    }
    return 0;
}

int tower_management(game_t *game)
{
    for (int i = 0; i < 32; i++) {
        if (TOWER[i].obj_status == 1) {
            tower_focus_update(game, &TOWER[i]);
            tower_attack_update(game, &TOWER[i]);
            tower_frame_update(game, &TOWER[i]);
        }
    }
    return 0;
}
