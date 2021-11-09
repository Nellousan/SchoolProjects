/*
** EPITECH PROJECT, 2019
** display management
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

int display_hud(game_t *game)
{
    sfVector2u size = sfTexture_getSize(HUD->h_bar_tex);
    size.x = size.x * PLAYER->hp / PLAYER->max_hp;
    sfSprite_setTextureRect(HUD->h_bar_spr, rect(0, 0, size.x, size.y));
    draw_sprite(game, HUD->h_bar_spr, HUD->position);
    draw_sprite(game, HUD->hud_spr, HUD->position);
    return 0;
}

int display_obstacles(game_t *game)
{
    int xoff = 0;
    for (int i = 0; O_MAP[i] != NULL; i++) {
        if (O_MAP[i]->sprite != NULL &&
        is_in_loading_range(game, O_MAP[i]->rect.left)) {
            xoff = (O_MAP[i]->type == 2) ? O_MAP[i]->rect.width / 2 : 0;
            draw_sprite(game, O_MAP[i]->sprite, vec2f((VMODE.width / 2) +
            (O_MAP[i]->rect.left - P_POS.x) - P_SWIDTH / 2 - xoff
            , O_MAP[i]->rect.top));
        }
    }
    return 0;
}

int display_management(game_t *game)
{
    sfRenderWindow_clear(WINDOW, sfBlack);
    display_background(game);
    display_obstacles(game);
    display_obj(game);
    display_player(game);
    display_player_atk(game);
    display_layout(game);
    display_hud(game);
    sfRenderWindow_display(WINDOW);
    return 0;
}
