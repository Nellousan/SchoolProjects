/*
** EPITECH PROJECT, 2020
** create enemy
** File description:
** Obiwan Kenobi
*/

#include <stdio.h>
#include "my_graph.h"
#include "def_def.h"
#include "def_structs.h"

o_mob_t create_mob(o_mob_t mob, game_t *game)
{
    static int counter = 0;
    sfVector2f pos = {10 - counter, 90};

    mob.id = MOBD[0]->id;
    mob.type = MOBD[0]->type;
    mob.max_hp = MOBD[0]->hp;
    mob.hp = mob.max_hp;
    mob.movespeed = 1;
    mob.frame = 1;
    mob.loot = 10;
    mob.pos = pos;
    mob.obj_status = 1;
    mob.move = 1;
    counter += 30;
    return (mob);
}

game_t *create_enemy(game_t *game)
{
    for (int i = 0; i < 15; i++)
        MOB[i] = create_mob(MOB[i], game);
    return (game);
}
