/*
** EPITECH PROJECT, 2019
** map load
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

o_map_t **load_obstacle_map(char *map)
{
    char *file = file_load(map);
    o_map_t **o_map = malloc(sizeof(o_map_t *) * (get_ret_count(file) + 1));
    int i = 0;
    int ret = 0;
    if (file == NULL)
        return NULL;
    ret = get_ret_count(file);
    for (i = 0; i < ret; i++) {
        o_map[i] = malloc(sizeof(o_map_t));
        o_map[i]->type = char_to_int(copy_until(&file, ';'));
        o_map[i]->rect = extract_rect(copy_until(&file, ';'));
        o_map[i]->spritesheet = copy_until(&file, '\n');
        if (o_map[i]->spritesheet[0] != '@')
            o_map[i]->sprite = sprite_create_from_file(o_map[i]->spritesheet);
        else
            o_map[i]->sprite = NULL;
    }
    o_map[i] = NULL;
    return o_map;
}

e_map_t **load_entity_map(void)
{
    char *file = file_load("data/entity_map_data");
    char *file_c = file;
    e_map_t **e_map = malloc(sizeof(e_map_t *) * (get_ret_count(file) + 1));
    int i = 0;
    int ret = get_ret_count(file);
    for (i = 0; i < ret; i++) {
        e_map[i] = malloc(sizeof(e_map_t));
        e_map[i]->status = 0;
        e_map[i]->id = char_to_int(copy_until(&file, ';'));
        e_map[i]->pos = extract_vect(copy_until(&file, '\n'));
    }
    e_map[i] = NULL;
    free(file_c);
    return e_map;
}

map_t *map_load(char *map_path)
{
    char *file = file_load("data/map_data");
    char *file_c = file;
    map_t *map = malloc(sizeof(map_t));
    map->parallax = char_to_int(copy_until(&file, ';'));
    map->spritesheet = malloc(sizeof(char *) * map->parallax);
    for (int i = 0; i < map->parallax; i++) {
        map->spritesheet[i] = copy_until(&file, ';');
    }
    map->starting_pos = extract_vect(copy_until(&file, ';'));
    map->o_map = load_obstacle_map(map_path);
    if (map->o_map == NULL)
        return NULL;
    map->music = sfMusic_createFromFile(run_strcat(
    "song/", copy_until(&file, ';')));
    free(file_c);
    return map;
}
