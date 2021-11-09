/*
** EPITECH PROJECT, 2020
** end screen
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

int end_screen_display(game_t *game)
{
    sfRenderWindow_clear(WINDOW, sfBlack);
    draw_sprite(game, END->bg_spr, vec2f(0, 0));
    draw_sprite(game, END->retry_spr,
    vec2f(END->retry_rect.left, END->retry_rect.top));
    draw_sprite(game, END->ts_spr,
    vec2f(END->ts_rect.left, END->ts_rect.top));
    sfRenderWindow_display(WINDOW);
    return 0;
}

int end_screen_click_button(game_t *game)
{
    if (!MOUSE_CLICK)
        return 1;
    if (pos_in_rect_check(CURSOR_POS, END->retry_rect))
        G_STATUS = stage;
    if (pos_in_rect_check(CURSOR_POS, END->ts_rect))
        G_STATUS = menu;
    return 0;
}

int end_screen(game_t *game)
{
    sfMusic_play(END->music);
    while (sfRenderWindow_isOpen(WINDOW) && G_STATUS == end) {
        TIME = sfClock_getElapsedTime(CLOCK);
        event_management(game);
        end_screen_display(game);
        end_screen_click_button(game);
    }
    sfMusic_stop(END->music);
    return 0;
}
