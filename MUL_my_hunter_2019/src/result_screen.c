/*
** EPITECH PROJECT, 2019
** result_screen
** File description:
**
*/

#include <stdlib.h>
#include <math.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "my_hunter.h"

void rs_scores_rectangles_draw(game_t *game)
{
    for (int i = 0; i < 8; i++) {
        draw_rect(game, sf_rect_init(XOFF + 64 + i, 310 + YOFF + i,
        150 - i * 2, 100 - i * 2), MYHUNDPURPLE);
        draw_rect(game, sf_rect_init(XOFF + 64 + i,
        YOFF + 460 + i, 150 - i * 2, 100 - i * 2),
        MYHUNDPURPLE);
        draw_rect(game, sf_rect_init(XOFF + 370 + i, 310 + YOFF + i,
        150 - i * 2, 100 - i * 2), MYHUNDPURPLE);
        draw_rect(game, sf_rect_init(XOFF + 370 + i, 460 + YOFF + i,
        150 - i * 2, 100 - i * 2), MYHUNDPURPLE);
    }
    return;
}

void rs_rectangles_draw(game_t *game)
{
    for (int i = 0; i < 16; i++) {
        draw_rect(game, sf_rect_init(XOFF + 32 + i, 200 + YOFF + 32 + i,
        VMODE->width - XOFF * 2 - i * 2 - 64, VMODE->height - (YOFF * 2) - i *
        2 - 32 - 200), MYHUNDGREEN);
        draw_rect(game, sf_rect_init(XOFF + 32 + i, YOFF - 32 + i,
        VMODE->width - XOFF * 2 - i * 2 - 64,
        VMODE->height - (YOFF * 2) - i * 2 - 400), MYHUNDPURPLE);
    }
    return;
}

void rs_background_display(game_t *game)
{
    sfSprite *sprite;
    sfRenderWindow_clear(WINDOW, sfBlack);
    sfTexture_updateFromPixels(TEX->framebuf, PIXARRAY,
    VMODE->width, VMODE->height, 0, 0);
    sprite = sprite_create(TEX->framebuf);
    sfRenderWindow_drawSprite(WINDOW, sprite, NULL);
    sfSprite_destroy(sprite);
    return;
}

void rs_display_management(game_t *game)
{
    rs_background_display(game);
    rs_draw_score(game);
    rs_draw_max_combo(game);
    rs_draw_accuracy(game);
    rs_draw_thundred(game);
    rs_draw_hundred(game);
    rs_draw_fifty(game);
    rs_draw_miss(game);
    display_cursor(game);
    sfRenderWindow_display(WINDOW);
    return;
}

void display_result_screen(game_t *game)
{
    framebuffer_clear(game);
    rs_rectangles_draw(game);
    rs_scores_rectangles_draw(game);
    game->status = 2;
    while (sfRenderWindow_isOpen(WINDOW)) {
        if (game->status == 0)
            return;
        rs_display_management(game);
        event_management(game);
    }
}
