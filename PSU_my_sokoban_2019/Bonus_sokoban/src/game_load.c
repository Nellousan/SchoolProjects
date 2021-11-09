/*
** EPITECH PROJECT, 2019
** game loading functions
** File description:
** 
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <curses.h>
#include "my.h"
#include "my_sokoban.h"

box_t *box_load(map_t *map, int box_count)
{
    box_t *box = malloc(sizeof(box_t) * box_count);
    int j = 0;
    int k = 0;
    for (int i = 0; map->draw_map[i] != '\0'; i++, k++) {
        if (map->draw_map[i] == '\n')
            i++;
        if (map->draw_map[i] == 'X') {
            map->draw_map[i] = ' ';
            box[j].status = 1;
            box[j].id = j;
            box[j].pos = vect_init(k % map->width, k / map->width);
            j++;
        }
    }
    return box;
}

vect_t *goal_load(map_t *map, int goal_count)
{
    vect_t *vect = malloc(sizeof(vect_t) * goal_count);
    int j = 0;
    int k = 0;
    for (int i = 0; map->draw_map[i] != '\0'; i++, k++) {
        if (map->draw_map[i] == '\n')
            i++;
        if (map->draw_map[i] == 'O') {
            vect[j] = vect_init(k % map->width, k / map->width);
            j++;
        }
    }
    return vect;
}

vect_t player_pos_init(map_t *map)
{
    int j = 0;
    for (int i = 0; map->draw_map[i] != '\0'; i++, j++) {
        if (map->draw_map[i] == '\n')
            i++;
        if (map->draw_map[i] == 'P') {
            map->draw_map[i] = ' ';
            return vect_init(j % map->width, j / map->width);
        }
    }
    return vect_init(0, 0);
}

game_t *game_load(char *filepath)
{
    game_t *game = malloc(sizeof(game_t));
    game->map_path = my_strdup(filepath);
    MAP = map_load(filepath);
    if (MAP == NULL)
        return NULL;
    if (!check_map_validity(game))
        return NULL;
    game->box_count = get_occurences(MAP->draw_map, 'X');
    BOX = box_load(MAP, game->box_count);
    game->goal_count = get_occurences(MAP->draw_map, 'O');
    GOALS = goal_load(MAP, game->goal_count);
    P_POS = player_pos_init(MAP);
    VMODE = video_mode_init(MWIDTH - 2, MHEIGHT - 2);
    TEX = tex_load();
    SPR = sprite_load(game);
    getmaxyx(stdscr, MAXH, MAXW);
    return game;
}

void game_reload(game_t *game)
{
    char *path = my_strdup(game->map_path);
    game_unload(game);
    game = game_load(path);
    free(path);
    return;
}
