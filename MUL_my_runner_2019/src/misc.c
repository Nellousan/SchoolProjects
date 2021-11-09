/*
** EPITECH PROJECT, 2019
** miscellaneous
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

void draw_sprite(game_t *game, sfSprite *spr, sfVector2f pos)
{
    sfSprite_setPosition(spr, pos);
    sfRenderWindow_drawSprite(WINDOW, spr, NULL);
    return;
}

int is_in_loading_range(game_t *game, int x)
{
    if (P_POS.x - x <= VMODE.width ||
        P_POS.x + x >= VMODE.width)
        return 1;
    return 0;
}

int get_array_size(void **array)
{
    int i = 0;
    while (array[i] != NULL) {
        i++;
    }
    return i;
}

void cat_help(void)
{
    char *file = file_load("help");
    my_printf("%s", file);
    return;
}
