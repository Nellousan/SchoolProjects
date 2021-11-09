/*
** EPITECH PROJECT, 2020
** tower_create
** File description:
** a
*/

#include "defender.h"

int create_tower(game_t *game, int id, sfVector2f pos)
{
    int i = 0;
    for (; TOWER[i].obj_status != 0; i++);
    TOWER[i].obj_status = 1;
    TOWER[i].id = TOWERD[id]->id;
    TOWER[i].damage = TOWERD[id]->damage;
    TOWER[i].range = TOWERD[id]->range;
    TOWER[i].pos = pos;
    return 0;
}
