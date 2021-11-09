/*
** EPITECH PROJECT, 2019
** framebuffer_draw
** File description:
** 
*/

#include <stdlib.h>
#include <math.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "my_hunter.h"

void my_putpixel(game_t *game, sfVector2f vect, sfColor color)
{
    PIXARRAY[(int)(vect.y * FRAMEBUFFER->width + vect.x) * 4] = color.r;
    PIXARRAY[(int)(vect.y * FRAMEBUFFER->width + vect.x) * 4 + 1] = color.g;
    PIXARRAY[(int)(vect.y * FRAMEBUFFER->width + vect.x) * 4 + 2] = color.b;
    PIXARRAY[(int)(vect.y * FRAMEBUFFER->width + vect.x) * 4 + 3] = color.a;
    return;
}

void draw_rect(game_t *game, sfIntRect rect, sfColor color)
{
    for (int i = 0; i < rect.width; i++)
        my_putpixel(game, sf_vector_init(rect.left + i, rect.top), color);
    for (int i = 0; i <= rect.width; i++)
        my_putpixel(game, sf_vector_init(rect.left + i, rect.top + rect.height),
        color);
    for (int i = 0; i < rect.height; i++)
        my_putpixel(game, sf_vector_init(rect.left, rect.top + i), color);
    for (int i = 0; i < rect.height; i++)
        my_putpixel(game, sf_vector_init(rect.left + rect.width, rect.top + i),
        color);
    return;
}

void draw_filled_rect(game_t *game, sfIntRect rect, sfColor color)
{
    for (int i = 0; i < rect.height; i++)
        for (int j = 0; j < rect.width; j++)
            my_putpixel(game, sf_vector_init(rect.left + j, rect.top + i),
            color);
    return;
}

void framebuffer_clear(game_t *game)
{
    for (unsigned int i = 0; i < VMODE->width * VMODE->height * 4; i++)
        PIXARRAY[i] = 0;
    return;
}
