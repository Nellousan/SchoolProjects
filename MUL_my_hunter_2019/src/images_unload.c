/*
** EPITECH PROJECT, 2019
** unload images
** File description:
** 
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <fcntl.h>
#include "my.h"
#include "my_hunter.h"

void unload_images(img_t *img)
{
    sfImage_destroy(img->duck_img);
    sfImage_destroy(img->appr_img);
    sfImage_destroy(img->hit300);
    sfImage_destroy(img->hit100);
    sfImage_destroy(img->hit50);
    sfImage_destroy(img->hitmiss);
    sfImage_destroy(img->background);
    sfImage_destroy(img->nb_sheet);
    sfImage_destroy(img->cursor);
    free(img);
    my_putstr("Images successfully unloaded.\n");
    return;
}

void unload_tex(tex_t *tex)
{
    sfTexture_destroy(tex->duck_tex);
    sfTexture_destroy(tex->appr_tex);
    sfTexture_destroy(tex->hit300);
    sfTexture_destroy(tex->hit100);
    sfTexture_destroy(tex->hit50);
    sfTexture_destroy(tex->hitmiss);
    sfTexture_destroy(tex->background);
    sfTexture_destroy(tex->framebuf);
    sfTexture_destroy(tex->cursor);
    for (int i = 0; i < 13; i++)
        sfTexture_destroy(tex->number[i]);
    free(tex);
    my_putstr("Textures successfully unloaded.\n");
    return;
}

void unload_sprites(spr_t *spr)
{
    sfSprite_destroy(spr->hit300);
    sfSprite_destroy(spr->hit100);
    sfSprite_destroy(spr->hit50);
    sfSprite_destroy(spr->hitmiss);
    sfSprite_destroy(spr->cursor);
    for (int i = 0; i < 13; i++)
        sfSprite_destroy(spr->number[i]);
    free(spr);
    my_putstr("Sprites successfully unloaded.\n");
    return;
}
