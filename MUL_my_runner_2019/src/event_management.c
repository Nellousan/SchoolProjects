/*
** EPITECH PROJECT, 2019
** event management
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

int event_management(game_t *game)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(WINDOW, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(WINDOW);
            return 1;
        }
        if (event.type == sfEvtMouseButtonPressed)
            MOUSE_CLICK = 1;
        else
            MOUSE_CLICK = 0;
        if (event.type == sfEvtMouseMoved)
            CURSOR_POS = vec2f(event.mouseMove.x, event.mouseMove.y);
    }
    return 0;
}
