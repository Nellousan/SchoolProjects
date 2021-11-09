/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include <stdlib.h>
#include <curses.h>
#include "my.h"
#include "my_sokoban.h"

vect_t get_map_size(char *map)
{
    int j = 0;
    int i = 0;
    vect_t vect;

    while (map[i] != '\n')
        i++;
    vect.x = i;
    for (i = 0; map[i] != '\0'; i++)
        if (map[i] == '\n')
            j++;
    vect.y = j + 1;
    return vect;
}

vect_t vect_init(int x, int y)
{
    vect_t vect;
    vect.x = x;
    vect.y = y;
    return vect;
}

vect_t vect_add(vect_t vect1, vect_t vect2)
{
    vect1.x += vect2.x;
    vect1.y += vect2.y;
    return vect1;
}

vect_t vect_sub(vect_t vect1, vect_t vect2)
{
    vect1.x -= vect2.x;
    vect1.y -= vect2.y;
    return vect1;
}

int get_occurences(char *map, char c)
{
    int occ = 0;
    for (int i = 0; map[i] != '\0'; i++)
        if (map[i] == c)
            occ++;
    return occ;
}
