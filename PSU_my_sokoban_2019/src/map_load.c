/*
** EPITECH PROJECT, 2019
** map loading fucns
** File description:
** 
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <curses.h>
#include "my.h"
#include "my_sokoban.h"

int check_map_validity(game_t *game)
{
    int p = 0;
    int x = 0;
    int o = 0;
    int i = 0;
    int j = 0;
    for (i = 0; DRAW_MAP[i] != '\0'; i++) {
        p += (DRAW_MAP[i] == 'P') ? 1 : 0;
        x += (DRAW_MAP[i] == 'X') ? 1 : 0;
        o += (DRAW_MAP[i] == 'O') ? 1 : 0;
        if (DRAW_MAP[i] != 'X' && DRAW_MAP[i] != 'O' && DRAW_MAP[i] != 'P' &&
        DRAW_MAP[i] != '#' && DRAW_MAP[i] != ' ' && DRAW_MAP[i] != '\n') {
            return 0;
        }
        j += (DRAW_MAP[i] == '\n') ? 1 : 0;
    }
    if (p != 1 || x == 0 || o == 0 || o != x)
        return 0;
    return 1;
}

char *raw_map_load(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return NULL;
    struct stat *fstats = malloc(sizeof(struct stat));
    fstat(fd, fstats);
    char *buffer = malloc(sizeof(char) * (fstats->st_size + 1));
    int size = read(fd, buffer, fstats->st_size);
    buffer[size] = '\0';
    close(fd);
    free(fstats);
    return buffer;
}

slot_t *slot_init(map_t *map)
{
    int i = 0;
    int j = 0;
    int x = 0;
    int y = 0;
    slot_t *slots = malloc(sizeof(slot_t) * my_strlen(map->draw_map));
    for (i = 0; map->draw_map[i] != '\0'; i++, x++, j++) {
        if (map->draw_map[i] == '\n') {
            x = 0;
            y++;
            i++;
        }
        slots[j].pos = vect_init(x, y);
        if (map->draw_map[i] == '#')
            slots[j].type = WALL;
        else if (map->draw_map[i] == 'O')
            slots[j].type = GOAL;
        else
            slots[j].type = LAND;
    }
    return slots;
}

map_t *map_load(char *filepath)
{
    map_t *map = malloc(sizeof(map_t));
    vect_t vect;
    map->draw_map = raw_map_load(filepath);
    if (map->draw_map == NULL)
        return NULL;
    vect = get_map_size(map->draw_map);
    map->width = vect.x;
    map->height = vect.y;
    map->slots = slot_init(map);
    return map;
}
