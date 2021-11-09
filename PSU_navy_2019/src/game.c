/*
** EPITECH PROJECT, 2020
** game.c
** File description:
** d
*/

#include <stdbool.h>
#include "my.h"
#include "navy.h"

static bool is_game_over(game_t *game)
{
    int hitc = 0;
    int i_lost = 1;
    for (int i = 0; i < 64; i++)
        if (MAP[i]->ship != 0 && MAP[i]->hit == 0)
            i_lost = 0;
    for (int i = 0; i < 64; i++)
        if (TMAP[i]->hit == 1)
            hitc++;
    if (hitc == 14) {
        RETURN_STATUS = 0;
        return true;
    }
    if (i_lost == 1) {
        RETURN_STATUS = 1;
        return true;
    }
    return false;
}

int game_loop(game_t *game)
{
    if (PLAYER == 2) {
        display_board(game);
        turn_wait(game);
    }
    while (!is_game_over(game)) {
        display_board(game);
        turn_attack(game);
        if (is_game_over(game))
            break;
        turn_wait(game);
    }
    if (RETURN_STATUS == 0)
        my_printf("I won\n");
    else
        my_printf("Enemy won\n");
    return 0;
}
