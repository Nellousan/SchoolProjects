/*
** EPITECH PROJECT, 2020
** tower display 
** File description:
** d
*/

#include "defender.h"

int display_towers(game_t *game)
{
    for (int i = 0; i < 32; i++)
        if (TOWER[i].obj_status == 1)
            draw_sprite(game, SPR->towers[TOWER[i].id][TOWER[i].frame],
            &TOWER[i].pos);
    return 0;
}
