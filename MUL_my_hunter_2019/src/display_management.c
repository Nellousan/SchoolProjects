/*
** EPITECH PROJECT, 2019
** display management
** File description:
** 
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "my_hunter.h"

void display_cursor(game_t *game)
{
    sfSprite_setPosition(SPR->cursor, CURSOR_POS);
    sfRenderWindow_drawSprite(WINDOW, SPR->cursor, NULL);
    return;
}

int background_display(game_t *game)
{
    sfSprite *background = sprite_create(game->tex->background);
    int xoffset = (game->mode->width - 1200) / 2;
    int yoffset = (game->mode->height - 1000) / 2;
    sfVector2f pos = sf_vector_init(xoffset, yoffset);
    sfSprite_setPosition(background, pos);
    sfRenderWindow_drawSprite(game->window, background, NULL);
    sfSprite_destroy(background);
    return 0;
}

int display_management(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    background_display(game);
    floating_scores_management(game);
    display_score(game);
    display_combo(game);
    display_accuracy(game);
    display_borders(game);
    display_cursor(game);
    for (int i = 0; DUCK_I.status != -1; i++) {
        if (DUCK_I.time_code - AR < TIME && DUCK_I.status != 2) {
            DUCK_I.status = 1;
            display_duck(game, &DUCK_I);
        }
    }
    sfRenderWindow_display(game->window);
    return 0;
}
