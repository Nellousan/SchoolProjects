/*
** EPITECH PROJECT, 2019
** unload game
** File description:
** 
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <fcntl.h>
#include "my.h"
#include "my_hunter.h"

void unload_game(game_t *game)
{
    unload_ducks(game->duck);
    unload_images(IMG);
    unload_tex(TEX);
    unload_sprites(SPR);
    unload_sounds(game->sound);
    free(PLAYER);
    free(PIXARRAY);
    free(FRAMEBUFFER);
    sfClock_destroy(game->clock);
    sfRenderWindow_destroy(WINDOW);
    free(VMODE);
    free(game);
    my_putstr("\nGame successfully unloaded.\n");
    return;
}
