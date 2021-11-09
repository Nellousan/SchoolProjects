/*
** EPITECH PROJECT, 2019
** event management
** File description:
** 
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "my_hunter.h"

int duck_hit_management(game_t *game, duck_t *duck, int offset);
int check_duck_hit(game_t *game, duck_t *duck, sfMouseButtonEvent event);

int click_management(game_t *game, sfMouseButtonEvent event)
{
    for (int i = 0; DUCK_I.status != -1; i++) {
        if (DUCK_I.status != 2 && check_duck_hit(game, &DUCK_I, event))
            return 1;
    }
    return 0;
}

int cursor_pos_refresh(game_t *game, sfMouseMoveEvent event)
{
    CURSOR_POS = sf_vector_init(event.x - 32, event.y - 32);
    return 0;
}

int event_management(game_t *game)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(game->window);
            return 0;
        }
        if (event.type == sfEvtMouseButtonPressed && game->status == 1)
            click_management(game, event.mouseButton);
        if (event.type == sfEvtMouseMoved)
            cursor_pos_refresh(game, event.mouseMove);
    }
    return 0;
}
