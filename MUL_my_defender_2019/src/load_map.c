/*
** EPITECH PROJECT, 2020
** load map 
** File description:
** p
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my.h"
#include "defender.h"
#include "a_malloc.h"

mapn_t **mapn_load(map_t *map, char *file)
{
    int size = map->size.x * map->size.y;
    int s = map->size.x - 1;
    mapn_t **mapn = a_malloc(sizeof(mapn_t *) * size | A_LIST(1));
    for (unsigned int i = 0; i < map->size.y - 1; i++) {
        for (unsigned int j = 0; i < map->size.x -1; i++) {
            mapn[i * s + j] = a_malloc(sizeof(mapn_t) | A_LIST(1));
            mapn[i * s + j]->pos = SFVEC2U(j, i);
            mapn[i * s + j]->type = file[0] - '0';
            file++;
        }
        file++;
    }
    return mapn;
}

map_t *map_load(void)
{
    map_t *map = a_malloc(sizeof(map_t) | A_LIST(1));
    char *file = file_load("data/map");
    int w;
    int h;
    map->sprsh = copy_until(&file, ';');
    w = char_to_int(copy_until(&file, ';'));
    h = char_to_int(copy_until(&file, ';'));
    map->size = SFVEC2U(h, w);
    map->nodesize = char_to_int(copy_until(&file, ';'));
    file++;
    map->mapn = mapn_load(map, file);
    return map;
}
