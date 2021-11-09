/*
** EPITECH PROJECT, 2020
** collision check
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

int pos_in_rect_check(sfVector2f vect, sfIntRect rect)
{
    if (vect.x > rect.left && vect.x < rect.left + rect.width &&
        vect.y > rect.top && vect.y < rect.top + rect.height)
        return 1;
    return 0;
}

int rect_collide_check(sfIntRect rect1, sfIntRect rect2)
{
    if (pos_in_rect_check(rect_topleft(rect1), rect2))
        return 1;
    if (pos_in_rect_check(rect_topright(rect1), rect2))
        return 1;
    if (pos_in_rect_check(rect_botleft(rect1), rect2))
        return 1;
    if (pos_in_rect_check(rect_botright(rect1), rect2))
        return 1;
    if (pos_in_rect_check(rect_topleft(rect2), rect1))
        return 1;
    if (pos_in_rect_check(rect_topright(rect2), rect1))
        return 1;
    if (pos_in_rect_check(rect_botleft(rect2), rect1))
        return 1;
    if (pos_in_rect_check(rect_botright(rect2), rect1))
        return 1;
    return 0;
}
