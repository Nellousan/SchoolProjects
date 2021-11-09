/*
** EPITECH PROJECT, 2019
** miscellaneous funcs
** File description:
** 
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "my_sokoban.h"

sfIntRect sf_rect_init(int top, int left, int w, int h)
{
    sfIntRect rect;
    rect.top = top;
    rect.left = left;
    rect.width = w;
    rect.height = h;
    return rect;
}

sfVideoMode video_mode_init(int w, int h)
{
    sfVideoMode mode = {w * 32 + 128, h * 32 + 128, 32};
    return mode;
}

sfVector2f sf_vect_init(float x, float y)
{
    sfVector2f vect;
    vect.x = x;
    vect.y = y;
    return vect;
}
