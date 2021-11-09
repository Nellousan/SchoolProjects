/*
** EPITECH PROJECT, 2020
** death screen
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

int death_screen_display(game_t *game)
{
    sfRenderWindow_clear(WINDOW, sfBlack);
    display_player(game);
    if (PLAYER->frame >= P_ANIMD[P_STATUS]->framecount - 1) {
        draw_sprite(game, G_OVER->bg_spr, vec2f(0, 0));
        draw_sprite(game, G_OVER->retry_spr,
        vec2f(G_OVER->retry_rect.left, G_OVER->retry_rect.top));
        draw_sprite(game, G_OVER->ts_spr,
        vec2f(G_OVER->ts_rect.left, G_OVER->ts_rect.top));
    }
    sfRenderWindow_display(WINDOW);
    return 0;
}

int death_screen_click_button(game_t *game)
{
    if (!MOUSE_CLICK)
        return 1;
    if (pos_in_rect_check(CURSOR_POS, G_OVER->retry_rect))
        G_STATUS = stage;
    if (pos_in_rect_check(CURSOR_POS, G_OVER->ts_rect))
        G_STATUS = menu;
    return 0;
}

int death_screen(game_t *game)
{
    sfMusic_play(G_OVER->music);
    while (sfRenderWindow_isOpen(WINDOW) && G_STATUS == death) {
        TIME = sfClock_getElapsedTime(CLOCK);
        event_management(game);
        player_frame_update(game);
        death_screen_display(game);
        death_screen_click_button(game);
    }
    sfMusic_stop(G_OVER->music);
    return 0;
}
