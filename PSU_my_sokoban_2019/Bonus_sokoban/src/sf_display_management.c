/*
** EPITECH PROJECT, 2019
** render window display
** File description:
** 
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "my_sokoban.h"

void draw_sprite(game_t *game, sfSprite *sprite, sfVector2f vect)
{
    sfSprite_setPosition(sprite, vect);
    sfRenderWindow_drawSprite(WINDOW, sprite, NULL);
    return;
}

void sf_draw_floor(game_t *game)
{
    for (int i = 0; i < (MWIDTH) * (MHEIGHT); i++) {
        if (SLOTS[i].pos.x == 0 && SLOTS[i].pos.y == 0) {
            sfSprite_setTextureRect(SPR->land,
            sf_rect_init(0, 0, 16, 16));
        } else if (SLOTS[i].pos.x == MWIDTH - 3 && SLOTS[i].pos.y == 0) {
            sfSprite_setTextureRect(SPR->land,
            sf_rect_init(0, 32, 16, 16));
        } else if (SLOTS[i].pos.x == 0 && SLOTS[i].pos.y == MHEIGHT - 3) {
            sfSprite_setTextureRect(SPR->land,
            sf_rect_init(64, 0, 16, 16));
        } else if (SLOTS[i].pos.x == MWIDTH - 3 && SLOTS[i].pos.y == MHEIGHT - 3) {
            sfSprite_setTextureRect(SPR->land,
            sf_rect_init(64, 32, 16, 16));
        } else if (SLOTS[i].pos.y == 0) {
            sfSprite_setTextureRect(SPR->land,
            sf_rect_init(0, 16, 16, 16));
        } else if (SLOTS[i].pos.y == MHEIGHT - 3) {
            sfSprite_setTextureRect(SPR->land,
            sf_rect_init(64, 16, 16, 16));
        } else if (SLOTS[i].pos.x == 0) {
            sfSprite_setTextureRect(SPR->land,
            sf_rect_init(16, 0, 16, 16));
        } else if (SLOTS[i].pos.x == MWIDTH - 3) {
            sfSprite_setTextureRect(SPR->land,
            sf_rect_init(16, 32, 16, 16));
        } else {
            sfSprite_setTextureRect(SPR->land,
            sf_rect_init(16 + 16 * SLOTS[i].rand, 16, 16, 16));
        }
        draw_sprite(game, SPR->land, sf_vect_init(
        64 + SLOTS[i].pos.x * 32, 64 + SLOTS[i].pos.y * 32));
    }
    return;
}

void sf_draw_exwall(game_t *game)
{
    sfSprite_setTextureRect(SPR->exwall, sf_rect_init(0, 0, 32, 32));
    draw_sprite(game, SPR->exwall, sf_vect_init(0, 0));
    sfSprite_setTextureRect(SPR->exwall, sf_rect_init(0, 48, 32, 32));
    draw_sprite(game, SPR->exwall, sf_vect_init(VMODE.width - 64, 0));
    sfSprite_setTextureRect(SPR->exwall, sf_rect_init(48, 0, 32, 32));
    draw_sprite(game, SPR->exwall, sf_vect_init(0, VMODE.height - 64));
    sfSprite_setTextureRect(SPR->exwall, sf_rect_init(48, 48, 32, 32));
    draw_sprite(game, SPR->exwall, sf_vect_init(VMODE.width - 64, VMODE.height - 64));
    for (int i = 0; i < MHEIGHT - 2; i++) {
        sfSprite_setTextureRect(SPR->exwall, sf_rect_init(32, 0, 32, 16));
        draw_sprite(game, SPR->exwall, sf_vect_init(0, 64 + 32 * i));
        sfSprite_setTextureRect(SPR->exwall, sf_rect_init(32, 48, 32, 16));
        draw_sprite(game, SPR->exwall, sf_vect_init(VMODE.width - 64, 64 + 32 * i));
    }
    for (int i = 0; i < MWIDTH - 2; i++) {
        sfSprite_setTextureRect(SPR->exwall, sf_rect_init(0, 32, 16, 32));
        draw_sprite(game, SPR->exwall, sf_vect_init(64 + 32 * i, 0));
        sfSprite_setTextureRect(SPR->exwall, sf_rect_init(48, 32, 16, 32));
        draw_sprite(game, SPR->exwall, sf_vect_init(64 + 32 * i, VMODE.height - 64));
    }
    return;
}

void sf_draw_walls(game_t *game)
{
    for (int i = 0; i < MWIDTH * MHEIGHT; i++) {
        if (SLOTS[i].type == WALL && SLOTS[i].pos.x != 0 &&
        SLOTS[i].pos.x != MWIDTH - 1 && SLOTS[i].pos.y != 0 &&
        SLOTS[i].pos.y != MHEIGHT - 1) {
            draw_sprite(game, SPR->wall,
            sf_vect_init(64 + (SLOTS[i].pos.x - 1) * 32,
            64 + (SLOTS[i].pos.y - 1) * 32 - 10));
        }
    }
    return;
}

void sf_draw_boxes(game_t *game)
{
    for (int i = 0; i < BOX_C; i++) 
        draw_sprite(game, SPR->box,
        sf_vect_init(64 + (BOX[i].pos.x - 1) * 32, 64 + (BOX[i].pos.y - 1) * 32));
    return;
}

void sf_draw_goals(game_t *game)
{
    for (int i = 0; i < GOALS_C; i++)
        draw_sprite(game, SPR->goal,
        sf_vect_init(64 + (GOALS[i].x - 1) * 32, 64 + (GOALS[i].y - 1) * 32));
    return;
}

void sf_draw_upper_player(game_t *game)
{
    sfIntRect rect = {0, 0, 32, 16};
    sfSprite_setTextureRect(SPR->sprsh, rect);
    draw_sprite(game, SPR->sprsh,
    sf_vect_init(48 + (P_POS.x - 1) * 32, 40 + (P_POS.y - 1) * 32));
    return;
}

void sf_draw_lower_player(game_t *game)
{
    sfIntRect rect = {0, 16, 32, 16};
    sfSprite_setTextureRect(SPR->sprsh, rect);
    draw_sprite(game, SPR->sprsh,
    sf_vect_init(48 + (P_POS.x - 1) * 32, 72 + (P_POS.y - 1) * 32));
    return;
}

void sf_display_management(game_t *game)
{
    sfRenderWindow_clear(WINDOW, sfBlack);
    sf_draw_floor(game);
    sf_draw_exwall(game);
    sf_draw_goals(game);
    sf_draw_lower_player(game);
    sf_draw_boxes(game);
    sf_draw_walls(game);
    sf_draw_upper_player(game);
    sfRenderWindow_display(WINDOW);
    return;
}
