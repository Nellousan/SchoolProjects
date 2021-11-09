/*
** EPITECH PROJECT, 2019
** map.h
** File description:
** map functions header
*/

typedef struct map
{
    sfVector2f *map_grid;
    char *map;
} map_t;

sfVector2f *map_grid_init(int x, int y);
char *map_load(char *map_name);
int map_sprite_management(sfRenderWindow *window, map_t *map);
