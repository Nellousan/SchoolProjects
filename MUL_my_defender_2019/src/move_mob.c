/*
** EPITECH PROJECT, 2020
** move_mob.c
** File description:
** Obiwan Kenobi
*/

#include <stdio.h>
#include "def_structs.h"
#include "def_def.h"

void mob_next_step(game_t *game, int i)
{
    if (MOB[i].move == 1 || MOB[i].move == 3 ||
    MOB[i].move == 5 || MOB[i].move == 7)
        MOB[i].pos.x += 5;
    if (MOB[i].move == 2 || MOB[i].move == 6)
        MOB[i].pos.y += 5;
    if (MOB[i].move == 4 || MOB[i].move == 8)
        MOB[i].pos.y -= 5;
    if (MOB[i].move == 9) {
        MOB[i].obj_status = 0;
        game->player->hp -= 20;
    }
}

void change_move(game_t *game, int i)
{
    if ((MOB[i].pos.x >= 240 && MOB[i].pos.y == 90 && MOB[i].pos.x < 520) ||
        (MOB[i].pos.x == 240 && MOB[i].pos.y >= 520) ||
        (MOB[i].pos.x == 520 && MOB[i].pos.y >= 520) ||
        (MOB[i].pos.x == 520 && MOB[i].pos.y == 90) ||
        (MOB[i].pos.x == 670 && MOB[i].pos.y == 90) ||
        (MOB[i].pos.x == 670 && MOB[i].pos.y == 455) ||
        (MOB[i].pos.x == 1020 && MOB[i].pos.y == 455) ||
        (MOB[i].pos.x == 1020 && MOB[i].pos.y == 90))
        MOB[i].move++;
}

void move_mob(game_t *game)
{
    for (int i = 0; i < 15; i++) {
        if (MOB[i].obj_status == 1) {
            change_move(game, i);
            mob_next_step(game, i);
        }
    }
}
