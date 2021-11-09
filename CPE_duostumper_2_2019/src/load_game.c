/*
** EPITECH PROJECT, 2020
** game load
** File description:
** game loading funcs
*/

#include <stdlib.h>
#include <string.h>
#include "a_malloc.h"
#include "stumper.h"

static void init_struct(game_t *game)
{
    SIZE = VECT(7, 6);
    P1 = 'X';
    P2 = 'O';
    REF = '#';
    BOARD = NULL;
    return;
}

static int set_parsed(game_t *game, char *av1, char *av2)
{
    if (!strcmp(av1, "-h"))
        SIZE.y = atoi(av2);
    if (!strcmp(av1, "-w"))
        SIZE.x = atoi(av2);
    if (!strcmp(av1, "-p1"))
        P1 = av2[0];
    if (!strcmp(av1, "-p2"))
        P2 = av2[0];
    if (!strcmp(av1, "-a"))
        REF = av2[0];
    return 1;
}

static int parse_args(game_t *game, int argc, char **argv)
{
    for (int i = 1; i < argc; i += 2) {
        set_parsed(game, argv[i], argv[i + 1]);
    }
    return 0;
}

game_t *game_load(int argc, char **argv)
{
    game_t *game;
    if (argc % 2 == 0)
        return NULL;
    game = a_malloc(sizeof(game_t) | A_LIST(1));
    init_struct(game);
    parse_args(game, argc, argv);
    if (SIZE.x * SIZE.y < 20)
        return NULL;
    BOARD = tab_maker(SIZE.x, SIZE.y);
    return game;
}
