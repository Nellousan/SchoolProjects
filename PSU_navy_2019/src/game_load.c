/*
** EPITECH PROJECT, 2020
** game load
** File description:
** a
*/

#include <stddef.h>
#include "my.h"
#include "navy.h"
#include "a_malloc.h"

static char *get_filepath(int argc, char **argv)
{
    if (argc > 2)
        return argv[2];
    else
        return argv[1];
}

vect_t extract_vect(char *str)
{
    if (my_strlen(str) != 2)
        return VECT(0, 0);
    return VECT((str[0] - 'A') + 1, str[1] - '0');
}

static mapn_t **map_load(void)
{
    mapn_t **map = a_malloc(sizeof(mapn_t *) * 64 | A_LIST(1));
    for (int i = 0; i < 64; i++) {
        map[i] = a_malloc(sizeof(mapn_t) | A_LIST(1));
        map[i]->pos = VECT(i % 8 + 1, i / 8 + 1);
        map[i]->hit = 0;
        map[i]->ship = 0;
    }
    return map;
}

game_t *game_load(int argc, char **argv)
{
    char *filepath = get_filepath(argc, argv);
    game_t *game = a_malloc(sizeof(game_t) | A_LIST(1));
    int check = 0;
    BOATS = boats_load(filepath);
    if (BOATS == NULL)
        return NULL;
    MAP = map_load();
    TMAP = map_load();
    if (argc < 3)
        PLAYER = 1;
    else {
        PLAYER = 2;
        E_PID = char_to_int(argv[1]);
    }
    RETURN_STATUS = 1;
    check = boats_placing(game);
    a_malloc(A_MALLOC_FREE);
    if (!check)
        return NULL;
    return game;
}
