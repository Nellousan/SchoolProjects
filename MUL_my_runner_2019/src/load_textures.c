/*
** EPITECH PROJECT, 2019
** load textures
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

tex_t *texture_load(game_t *game)
{
    tex_t *tex = malloc(sizeof(tex_t));
    tex->player = sfTexture_createFromFile(
    run_strcat(SPR_DIR, PLAYER->spritesheet), NULL);
    tex->background = malloc(sizeof(sfTexture *) * MAP->parallax);
    tex->entity = malloc(sizeof(sfTexture *) * get_array_size((void **)E_LIST));
    for (int i = 0; i < MAP->parallax; i++)
        tex->background[i] = sfTexture_createFromFile(
        run_strcat(SPR_DIR, MAP->spritesheet[i]), NULL);
    for (int i = 0; i < get_array_size((void **)E_LIST); i++)
        tex->entity[i] = sfTexture_createFromFile(
        run_strcat(SPR_DIR, E_LIST[i]->spritesheet), NULL);
    return tex;
}
