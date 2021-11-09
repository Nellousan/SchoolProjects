/*
** EPITECH PROJECT, 2020
** title screen
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

int title_screen_display(game_t *game)
{
    sfRenderWindow_clear(WINDOW, sfBlack);
    draw_sprite(game, TS->bg_spr, vec2f(0, 0));
    draw_sprite(game, TS->quit_spr,
    vec2f(TS->quit_rect.left, TS->quit_rect.top));
    draw_sprite(game, TS->start_spr,
    vec2f(TS->start_rect.left, TS->start_rect.top));
    sfRenderWindow_display(WINDOW);
    return 0;
}

int title_screen_click_button(game_t *game)
{
    if (!MOUSE_CLICK)
        return 1;
    if (pos_in_rect_check(CURSOR_POS, TS->start_rect))
        G_STATUS = stage;
    if (pos_in_rect_check(CURSOR_POS, TS->quit_rect))
        G_STATUS = quit;
    return 0;
}

int title_screen(game_t *game)
{
    sfMusic_play(TS->music);
    while (sfRenderWindow_isOpen(WINDOW) && G_STATUS == menu) {
        TIME = sfClock_getElapsedTime(CLOCK);
        event_management(game);
        player_frame_update(game);
        title_screen_display(game);
        title_screen_click_button(game);
    }
    sfMusic_stop(TS->music);
    return 0;
}
