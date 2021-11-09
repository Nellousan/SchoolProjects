/*
** EPITECH PROJECT, 2019
** background display
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

int double_draw(game_t *game, int i, sfVector2f p_pos)
{
    sfVector2u size = sfTexture_getSize(TEX->background[i]);
    sfVector2f pos = vec2f((int)size.x -
    (int)(p_pos.x / (MAP->parallax - i)) % size.x, 0);
    draw_sprite(game, SPR->background[i], pos);
    pos = vec2f(pos.x - size.x, 0);
    draw_sprite(game, SPR->background[i], pos);
    return 0;
}

int display_background(game_t *game)
{
    for (int i = 0; i < MAP->parallax - 1; i++) {
        double_draw(game, i, P_POS);
    }
    return 0;
}

int display_layout(game_t *game)
{
    double_draw(game, MAP->parallax - 1, P_POS);
    return 0;
}
