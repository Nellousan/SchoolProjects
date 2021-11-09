/*
** EPITECH PROJECT, 2020
** load player
** File description:
** m
*/

#include "defender.h"
#include "my.h"
#include "a_malloc.h"

player_t *player_load(void)
{
    player_t *player = a_malloc(sizeof(player_t) | A_LIST(1));
    player->hp = 500;
    player->gold = 300;
    return player;
}
