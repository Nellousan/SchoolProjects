/*
** EPITECH PROJECT, 2020
** game status selector
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

int game_status_selector(game_t *game)
{
    while (sfRenderWindow_isOpen(WINDOW) && G_STATUS != quit) {
        if (G_STATUS == menu)
            title_screen(game);
        if (G_STATUS == stage)
            game_loop(game);
        if (G_STATUS == death)
            death_screen(game);
        if (G_STATUS == end)
            end_screen(game);
    }
    return 0;
}
