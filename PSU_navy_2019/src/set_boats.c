/*
** EPITECH PROJECT, 2020
** set boats
** File description:
** boats setting
*/

#include "my.h"
#include "navy.h"
#include "a_malloc.h"

int set_destr(vect_t v1, vect_t v2, boats_t *boats)
{
    boats->destroyer[0] = v1;
    boats->destroyer[1] = v2;
    return 1;
}

int set_sub(vect_t v1, vect_t v2, boats_t *boats)
{
    boats->submarine[0] = v1;
    boats->submarine[1] = v2;
    return 1;
}

int set_battleship(vect_t v1, vect_t v2, boats_t *boats)
{
    boats->battleship[0] = v1;
    boats->battleship[1] = v2;
    return 1;
}

int set_cruiser(vect_t v1, vect_t v2, boats_t *boats)
{
    boats->cruiser[0] = v1;
    boats->cruiser[1] = v2;
    return 1;
}
