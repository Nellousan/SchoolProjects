/*
** EPITECH PROJECT, 2019
** display_borders
** File description:
** 
*/

#include <stdlib.h>
#include <math.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "my_hunter.h"

void draw_rect_filler(game_t *game)
{
    double y = (double) 1000 / (BPM / 60) / 2;
    double bpm_rhythm = (10 * exp(3.4 * cos((TIME - BPM_OFFSET) * M_PI / y)));
    int rect_top_offset = bpm_rhythm / 10;
    int combo_ratio = (VMODE->height - 192) * PLAYER->combo / game->duck_amnt;
    int rect_height = combo_ratio + rect_top_offset;
    int rect_top = VMODE->height - 48 - rect_height;
    sfIntRect left_rect = sf_rect_init(48, rect_top,
    XOFF - 48 * 2 + 1, rect_height + 1);
    sfIntRect right_rect = sf_rect_init(VMODE->width - XOFF + 48, rect_top,
    XOFF - 48 * 2 + 1, rect_height + 1);
    sfRectangleShape *left_rectshape = sf_rectshape_init(left_rect, MYHUNGREEN);
    sfRectangleShape *right_rectshape = sf_rectshape_init(right_rect,
    MYHUNPURPLE);
    sfRenderWindow_drawRectangleShape(WINDOW, left_rectshape, NULL);
    sfRenderWindow_drawRectangleShape(WINDOW, right_rectshape, NULL);
    return;
}

void draw_border_rects(game_t *game)
{
    for (int i = 0; i < 16; i++) {
        draw_rect(game, sf_rect_init(32 + i, 32 + i,
        XOFF - 64 - i * 2, VMODE->height - 64 - i * 2),
        MYHUNDGREEN);
        draw_rect(game, sf_rect_init(VMODE->width - XOFF + 32 + i,
        32 + i, XOFF - 64 - i * 2, VMODE->height - 64 - i * 2),
        MYHUNDPURPLE);
    }
    return;
}

void display_borders(game_t *game)
{
    sfSprite *sprite;
    draw_rect_filler(game);
    sfTexture_updateFromPixels(TEX->framebuf, PIXARRAY,
    VMODE->width, VMODE->height, 0, 0);
    sprite = sprite_create(TEX->framebuf);
    sfRenderWindow_drawSprite(WINDOW, sprite, NULL);
    sfSprite_destroy(sprite);
    return;
}
