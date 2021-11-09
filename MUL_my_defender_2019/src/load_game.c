/*
** EPITECH PROJECT, 2020
** game loading functions
** File description:
** a
*/

#include <SFML/Graphics.h>
#include "my.h"
#include "defender.h"
#include "a_malloc.h"

game_t *game_load(void)
{
    game_t *game = a_malloc(sizeof(game_t) | A_LIST(1));
    OBJ = a_malloc(sizeof(obj_t) | A_LIST(1));
    MAP = map_load();
    PLAYER = player_load();
    TOWERD = tower_load();
    MOBD = mob_load();
    SPR = sprite_load(game);
    VMODE = SFVMODE(1200, 800, 32);
    BUTTON = NULL;
    WINDOW = sfRenderWindow_create(VMODE, WINNAME, sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(WINDOW, 60);
    a_malloc(A_MALLOC_FREE);
    return game;
}
