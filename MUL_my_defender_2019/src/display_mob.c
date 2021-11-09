/*
** EPITECH PROJECT, 2020
** display mob
** File description:
** Obiwan Kenobi
*/

#include "my_graph.h"
#include "def_def.h"
#include "def_structs.h"

void display_mob(game_t *game, sfSprite *sprite)
{
    for (int i = 0; i < 32; i++) {
        if (MOB[i] != NULL) {
            sfRenderWindow_drawSprite(game->window, sprite, NULL);
        }
    }
}
