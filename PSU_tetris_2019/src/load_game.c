/*
** EPITECH PROJECT, 2020
** load
** File description:
** game
*/

#include <stdbool.h>
#include <curses.h>
#include "tetris.h"
#include "my.h"
#include "a_malloc.h"

static bool is_sorted(game_t *game)
{
    for (int i = 0; TETRI[i + 1] != NULL; i++)
        if (my_strcmp(TETRI[i]->name, TETRI[i + 1]->name) == 1)
            return false;
    return true;
}

static void sort_tetriminos(game_t *game)
{
    tetri_t *tmp;
    for (int i = 0; !is_sorted(game); i = (TETRI[i + 2] == NULL) ? 0 : i + 1) {
        if (my_strcmp(TETRI[i]->name, TETRI[i + 1]->name) == 1) {
            tmp = TETRI[i + 1];
            TETRI[i + 1] = TETRI[i];
            TETRI[i] = tmp;
        }
    }
    return;
}

static void options_generate_default(game_t *game)
{
    game->options = a_malloc(sizeof(opt_t) | A_LIST(1));
    LEVEL = 1;
    LEFT_KEY = KEY_LEFT;
    RIGHT_KEY = KEY_RIGHT;
    TURN_KEY = KEY_UP;
    DROP_KEY = KEY_DOWN;
    QUIT_KEY = 'q';
    PAUSE_KEY = ' ';
    MAP_SIZE = VECT(10, 20);
    HELP = false;
    WO_NEXT = false;
    DBG = false;
    return;
}

game_t *game_load(int argc, char **argv)
{
    game_t *game = a_malloc(sizeof(game_t) | A_LIST(1));
    options_generate_default(game);
    options_load(game, argc, argv);
    TETRI = tetri_load();
    sort_tetriminos(game);
    a_malloc(A_MALLOC_FREE);
    return game;
}

        
