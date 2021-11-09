/*
** EPITECH PROJECT, 2020
** obj_managament.c	
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

int obj_init(game_t *game)
{
    OBJ = malloc(sizeof(obj_t *) * 32);
    for (int i = 0; i < 32; i++) {
        OBJ[i] = malloc(sizeof(obj_t));
        OBJ[i]->obj_status = 0;
    }
    return 0;
}

void fuck_la_norme_v3(game_t *game, obj_t *obj)
{
    obj->spawn_time = sfClock_getElapsedTime(CLOCK);
    obj->pos_time = obj->spawn_time;
    obj->status_time = obj->spawn_time;
    obj->attack_time = obj->spawn_time;
    obj->frame_time = obj->spawn_time;
    return;
}

int obj_create(game_t *game, int id, e_map_t *mapdata)
{
    int i = 0;
    for (i = 0; OBJ[i]->obj_status != 0 && i < 32; i++);
    OBJ[i]->id = id;
    OBJ[i]->obj_status = 1;
    OBJ[i]->frame = 0;
    OBJ[i]->e_status = o_run;
    OBJ[i]->name = E_LIST[id]->name;
    OBJ[i]->damage = E_LIST[id]->damage;
    OBJ[i]->type = E_LIST[id]->type;
    OBJ[i]->hurtbox = E_LIST[id]->hurtbox;
    OBJ[i]->hitbox = E_LIST[id]->hitbox;
    OBJ[i]->hp = E_LIST[id]->hp;
    OBJ[i]->behaviour = E_LIST[id]->behaviour;
    OBJ[i]->run_spd = E_LIST[id]->run_spd;
    OBJ[i]->pos = mapdata->pos;
    fuck_la_norme_v3(game, OBJ[i]);
    OBJ[i]->dmg_time.microseconds = 0;
    OBJ[i]->facing = LEFT;
    return 0;
}

