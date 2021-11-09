/*
** EPITECH PROJECT, 2020
** event management
** File description:
** a
*/

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include "defender.h"

static int tower_creation_sender(game_t *game, sfMouseButtonEvent mouse_b)
{
    sfVector2f pos = SFVEC2F(mouse_b.x, mouse_b.y);
    create_tower(game, 0, pos);
    return 0;
}

int event_management(game_t *game)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(WINDOW, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(WINDOW);
            return 1;
        }
        if (event.type == sfEvtMouseButtonPressed)
            tower_creation_sender(game, event.mouseButton);
    }
    return 0;
}
