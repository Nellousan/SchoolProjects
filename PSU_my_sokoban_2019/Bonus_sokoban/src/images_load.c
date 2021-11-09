/*
** EPITECH PROJECT, 2019
** images load
** File description:
** 
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "my_sokoban.h"

sfSprite *sprite_create(sfTexture *tex)
{
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, tex, sfTrue);
    sfSprite_setScale(sprite, sf_vect_init(2, 2));
    return sprite;
}

tex_t *tex_load(void)
{
    tex_t *tex = malloc(sizeof(tex_t));
    tex->spr_sheet = sfTexture_createFromFile("sprites/spritesheet.png", NULL);
    tex->land = sfTexture_createFromFile("sprites/land.png", NULL);
    tex->wall = sfTexture_createFromFile("sprites/wall.png", NULL);
    tex->exwall = sfTexture_createFromFile("sprites/ext_walls.png", NULL);
    tex->box = sfTexture_createFromFile("sprites/box.png", NULL);
    tex->goal = sfTexture_createFromFile("sprites/goal.png", NULL);
    return tex;
}

spr_t *sprite_load(game_t *game)
{
    spr_t *spr = malloc(sizeof(spr_t));
    spr->sprsh = sprite_create(TEX->spr_sheet);
    spr->land = sprite_create(TEX->land);
    spr->wall = sprite_create(TEX->wall);
    spr->exwall = sprite_create(TEX->exwall);
    spr->box = sprite_create(TEX->box);
    spr->goal = sprite_create(TEX->goal);
    return spr;
}
