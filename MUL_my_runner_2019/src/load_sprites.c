/*
** EPITECH PROJECT, 2019
** sprite load
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

sfSprite ***player_spr_load(game_t *game)
{
    sfSprite ***sprarr = malloc(sizeof(sfSprite **) * 8);
    int i = 0;
    for (i = 0; i < 7; i++)
        sprarr[i] = sprite_array_load(TEX->player,
        PLAYER->sprite_rect, PLAYER->anim_data[i]->framecount, i);
    sprarr[i] = NULL;
    return sprarr;
}

sfSprite ****entity_spr_load(game_t *game)
{
    int e_count = get_array_size((void **)E_LIST);
    sfSprite ****spr = malloc(sizeof(sfSprite ***) * (e_count + 1));
    int i = 0;
    int j = 0;
    for (i = 0; i < e_count; i++) {
        spr[i] = malloc(sizeof(sfSprite **) * 4);
        for (j = 0; j < 3; j++)
            spr[i][j] = sprite_array_load(TEX->entity[i],
            E_LIST[i]->sprite_rect, E_LIST[i]->anim_data[j]->framecount, j);
        spr[i][j] = NULL;
    }
    spr[i] = NULL;
    return spr;
}

spr_t *sprite_load(game_t *game)
{
    spr_t *spr = malloc(sizeof(spr_t));
    spr->player = player_spr_load(game);
    spr->entity = entity_spr_load(game);
    spr->background = malloc(sizeof(sfSprite *) * MAP->parallax);
    for (int i = 0; i < MAP->parallax; i++)
        spr->background[i] = sprite_create(TEX->background[i], NULL);
    return spr;
}
