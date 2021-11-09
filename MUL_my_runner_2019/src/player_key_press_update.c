/*
** EPITECH PROJECT, 2020
** key_press_update
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

int player_key_press_update(game_t *game)
{
    int key_press = 0;
    for (int i = 0; i < 4 && P_STATUS != atk; i++)
        if (sfKeyboard_isKeyPressed(KEY[i]->code)) {
            (KEY[i]->fptr)(game);
            key_press = 1;
        }
    for (int i = 0; i < get_array_size((void **)P_ATK); i++) {
        if (sfKeyboard_isKeyPressed(P_ATK[i]->key)) {
            player_attack_management(game, P_ATK[i]);
            PLAYER->atk_id = P_ATK[i]->id;
            key_press = 1;
        }
    }
    if (!key_press && MSEC(TIME) - MSEC(PLAYER->atk_time) >
        PLAYER->atk_cd)
        no_key(game);
    return 0;
}
