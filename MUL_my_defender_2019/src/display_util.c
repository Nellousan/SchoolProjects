/*
** EPITECH PROJECT, 2020
** display 
** File description:
** util
*/

#include <SFML/Graphics.h>
#include "defender.h"

int draw_sprite(game_t *game, sfSprite *spr, sfVector2f *pos)
{
    if (pos)
        sfSprite_setPosition(spr, *pos);
    sfRenderWindow_drawSprite(WINDOW, spr, NULL);
    return 0;
}
