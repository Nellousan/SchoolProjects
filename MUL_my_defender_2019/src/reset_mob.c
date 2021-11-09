/*
** EPITECH PROJECT, 2020
** reset_mob
** File description:
** Obiwan Kenobi
*/

#include "defender.h"

void reset_mob(game_t *game)
{
    for (int i = 0; i < 15; i++) {
        if (MOB[i].obj_status == 1 && MOB[i].hp <= 0)
            MOB[i].obj_status = 0;
    }
}
