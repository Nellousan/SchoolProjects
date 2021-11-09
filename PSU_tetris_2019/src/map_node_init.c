/*
** EPITECH PROJECT, 2020
** init
** File description:
** map
*/

#include <stdlib.h>
#include <stdbool.h>
#include "tetris.h"
#include "a_malloc.h"

void map_line_destroy(mapn_t **mapn)
{
    for (int i = 0; mapn[i] != NULL; i++) {
        free(mapn[i]);
    }
    free(mapn);
    return;
}

static mapn_t *init_map_node(void)
{
    mapn_t *mapn = malloc(sizeof(mapn_t));
    mapn->is_occupied = false;
    mapn->c = ' ';
    mapn->color = 0;
    return mapn;
}

mapn_t **init_line(game_t *game)
{
    mapn_t **mapn = malloc(sizeof(mapn_t *) * (MAP_SIZE.x + 1));
    int i = 0;
    for (i = 0; i < MAP_SIZE.x; i++) {
        mapn[i] = init_map_node();
    }
    mapn[i] = NULL;
    return mapn;
}

int init_map(game_t *game)
{
    int i = 0;
    MAPN = a_malloc(sizeof(mapn_t **) * (MAP_SIZE.y + 1));
    for (i = 0; i < MAP_SIZE.y; i++) {
        MAPN[i] = init_line(game);
    }
    MAPN[i] = NULL;
    return 0;
}
