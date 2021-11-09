/*
** EPITECH PROJECT, 2019
** BSQ Header
** File description:
** 
*/

#ifndef BSQ_H
#define BSQ_H

#include <SFML/Graphics.h>

/*************** DEFINE ***************/

#define NORM_DEF (sq->y - i) * len + sq->x - j

/************** STRUCTS ***************/

typedef struct sq_vect
{
    int x;
    int y;
    int size;
} sq_vect_t;

typedef struct map_grid
{
    sfVector2f *grid;
    int size;
} map_grid_t;

/************* MAIN FUNCS *************/

int bsq(char *map, sq_vect_t *big_sq);
int graph_bsq(char *map, sq_vect_t *q);

/*************** MAP ******************/

char *load_map(char *path);

/*************  INITS. ****************/

sq_vect_t *sq_init(void);
my_vect *my_vect_init(void);
sfVector2f *map_grid_init(int x, int y);

/************** MISC. *****************/

int move_map_ptr(char **map);
int get_line_len(char *map);
int get_ret_count(char *map);

/************ SP CASES *****************/

int line_case(char *map);

/***************************************/

#endif
