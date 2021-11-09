/*
** EPITECH PROJECT, 2020
** load
** File description:
** sprites
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my.h"
#include "defender.h"
#include "a_malloc.h"

static sfSprite ***load_mob_sprites(game_t *game)
{
    int m_amnt;
    sfSprite ***sprarr;
    sfIntRect rect = {0, 0, 32, 32};
    int i = 0;
    for (m_amnt = 0; MOBD[m_amnt] != NULL; m_amnt++);
    sprarr = a_malloc(sizeof(sfSprite **) * (m_amnt + 1) | A_LIST(1));
    for (i = 0; MOBD[i] != NULL; i++)
        sprarr[i] = load_sprite_array(MOBD[i]->sprsh, rect, 2);
    sprarr[i] = NULL;
    return sprarr;
}

static sfSprite ***load_tower_sprites(game_t *game)
{
    int t_amnt;
    sfSprite ***sprarr;
    sfIntRect rect = {0, 0, 32, 32};
    int i = 0;
    for (t_amnt = 0; TOWERD[t_amnt] != NULL; t_amnt++);
    sprarr = a_malloc(sizeof(sfSprite **) * (t_amnt + 1) | A_LIST(1));
    for (i = 0; TOWERD[i] != NULL; i++)
        sprarr[i] = load_sprite_array(TOWERD[i]->sprsh, rect, 2);
    sprarr[i] = NULL;
    return sprarr;
}

spr_t *sprite_load(game_t *game)
{
    spr_t *spr = a_malloc(sizeof(spr_t) | A_LIST(1));
    spr->mob = load_mob_sprites(game);
    spr->towers = load_tower_sprites(game);
    spr->map = sprite_create_from_file(MAP->sprsh, NULL);
    return spr;
}
