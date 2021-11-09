/*
** EPITECH PROJECT, 2019
** misc2
** File description:
** 
*/

#include <stdlib.h>
#include <math.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "my_hunter.h"

sfColor sf_color_init(int r, int g, int b, int a)
{
    sfColor color;
    color.r = r;
    color.g = g;
    color.b = b;
    color.a = a;
    return color;
}

sfIntRect sf_rect_init(int left, int top, int width, int height)
{
    sfIntRect rect;
    rect.left = left;
    rect.top = top;
    rect.width = width;
    rect.height = height;
    return rect;
}

sfRectangleShape *sf_rectshape_init(sfIntRect rect, sfColor color)
{
    sfRectangleShape *rectshape = sfRectangleShape_create();
    sfRectangleShape_setSize(rectshape,
    sf_vector_init(rect.width, rect.height));
    sfRectangleShape_setFillColor(rectshape, color);
    sfRectangleShape_setPosition(rectshape,
    sf_vector_init(rect.left, rect.top));
    return rectshape;
}

char *sp_cat(char *str1, char *str2, char *str3)
{
    char *buffer = malloc(sizeof(char) * (my_strlen(str1) +
    my_strlen(str2) + my_strlen(str3) + 1));
    int i = 0;

    for (int j = 0; str1[j] != '\0'; j++, i++)
        buffer[i] = str1[j];
    for (int j = 0; str2[j] != '\0'; j++, i++)
        buffer[i] = str2[j];
    for (int j = 0; str3[j] != '\0'; j++, i++)
        buffer[i] = str3[j];
    buffer[i] = '\0';
    return buffer;
}

void sf_draw_sprite(game_t *game, sfSprite *sprite, sfVector2f vect)
{
    sfSprite_setPosition(sprite, vect);
    sfRenderWindow_drawSprite(WINDOW, sprite, NULL);
    return;
}
