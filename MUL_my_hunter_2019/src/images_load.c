/*
** EPITECH PROJECT, 2019
** textures load
** File description:
** 
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <fcntl.h>
#include "my.h"
#include "my_hunter.h"

img_t *load_images(void)
{
    img_t *img = malloc(sizeof(img_t));
    img->duck_img = sfImage_createFromFile("sprites/square_sheet.png");
    img->appr_img = sfImage_createFromFile("sprites/approach_sheet.png");
    img->hit300 = sfImage_createFromFile("sprites/hit300.png");
    img->hit100 = sfImage_createFromFile("sprites/hit100.png");
    img->hit50 = sfImage_createFromFile("sprites/hit50.png");
    img->hitmiss = sfImage_createFromFile("sprites/hitmiss.png");
    img->background = sfImage_createFromFile("sprites/background.png");
    img->nb_sheet = sfImage_createFromFile("sprites/number_sheet.png");
    img->cursor = sfImage_createFromFile("sprites/cursor.png");
    return img;
}

sfTexture **load_number_tex(game_t *game)
{
    sfTexture **tex = malloc(sizeof(sfTexture *) * 13);
    sfIntRect rect;
    for (int i = 0; i < 13; i++) {
        rect = sf_rect_init(44 * i, 0, 44, 64);
        tex[i] = sfTexture_createFromImage(IMG->nb_sheet, &rect);
    }
    return tex;
}

tex_t *load_tex(game_t *game)
{
    tex_t *tex = malloc(sizeof(tex_t));
    tex->duck_tex = sfTexture_createFromImage(IMG->duck_img, NULL);
    tex->appr_tex = sfTexture_createFromImage(IMG->appr_img, NULL);
    tex->hit300 = sfTexture_createFromImage(IMG->hit300, NULL);
    tex->hit100 = sfTexture_createFromImage(IMG->hit100, NULL);
    tex->hit50 = sfTexture_createFromImage(IMG->hit50, NULL);
    tex->hitmiss = sfTexture_createFromImage(IMG->hitmiss, NULL);
    tex->background = sfTexture_createFromImage(IMG->background, NULL);
    tex->framebuf = sfTexture_create(VMODE->width, VMODE->height);
    tex->number = load_number_tex(game);
    tex->cursor = sfTexture_createFromImage(IMG->cursor, NULL);
    return tex;
}

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *framebuffer = malloc(sizeof(framebuffer_t));
    framebuffer->pixarray = malloc(sizeof(sfUint8) * width * height * 4);
    framebuffer->width = width;
    framebuffer->height = height;
    return framebuffer;
}

spr_t *load_sprites(game_t *game)
{
    spr_t *spr = malloc(sizeof(spr_t));
    spr->hit300 = sprite_create(TEX->hit300);
    spr->hit100 = sprite_create(TEX->hit100);
    spr->hit50 = sprite_create(TEX->hit50);
    spr->hitmiss = sprite_create(TEX->hitmiss);
    spr->number = malloc(sizeof(sfSprite *) * 13);
    for (int i = 0; i < 13; i++)
        spr->number[i] = sprite_create(TEX->number[i]);
    spr->cursor = sprite_create(TEX->cursor);
    return spr;
}
