/*
** EPITECH PROJECT, 2020
** display management
** File description:
** a
*/

#include <SFML/Graphics.h>
#include "defender.h"

static int display_map(game_t *game)
{
    sfVector2f vect = SFVEC2F(0, 0);
    draw_sprite(game, SPR->map, &vect);
    return 0;
}

int display_management(game_t *game)
{
    sfRenderWindow_clear(WINDOW, sfBlack);
    display_map(game);
    display_towers(game);
    display_enemies(game);
    sfRenderWindow_display(WINDOW);
    return 0;
}
