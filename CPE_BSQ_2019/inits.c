/*
** EPITECH PROJECT, 2019
** bsq init funcs
** File description:
** 
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "bsq.h"

sfVector2f *map_grid_init(int x, int y)
{
    sfVector2f *map_grid = malloc(sizeof(sfVector2f) * x * y);
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            map_grid[i * x + j].x = j * 32;
            map_grid[i * x + j].y = i * 32;
        }
    }
    return map_grid;
}

sq_vect_t *sq_init(void)
{
    sq_vect_t *buffer = malloc(sizeof(sq_vect_t));
    buffer->x = 0;
    buffer->y = 0;
    buffer->size = 1;
    return buffer;
}

my_vect *my_vect_init(void)
{
    my_vect *buffer = malloc(sizeof(my_vect));
    buffer->x = 0;
    buffer->y = 0;
    return buffer;
}
