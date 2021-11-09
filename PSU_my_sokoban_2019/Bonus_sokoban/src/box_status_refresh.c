/*
** EPITECH PROJECT, 2019
** box status refresh
** File description:
** 
*/

#include <stdlib.h>
#include <curses.h>
#include "my.h"
#include "my_sokoban.h"

int slot_type(game_t *game, vect_t vect)
{
    if (DRAW_MAP[(MWIDTH + 1) * vect.y + vect.x] == WALL)
        return WALL;
    else if (DRAW_MAP[(MWIDTH + 1) * vect.y + vect.x] == GOAL)
        return GOAL;
    return LAND;
}

int is_stuck(game_t *game, int id)
{
    char up = slot_type(game, POS_UP(BOX[id].pos));
    char down = slot_type(game, POS_DOWN(BOX[id].pos));
    char left = slot_type(game, POS_LEFT(BOX[id].pos));
    char right = slot_type(game, POS_RIGHT(BOX[id].pos));
    if ((up == WALL && right == WALL) || (up == WALL && left == WALL) ||
        (down == WALL && right == WALL) || (down == WALL && left == WALL))
        return 1;
    return 0;
}

void box_status_refresh(game_t *game)
{
    for (int i = 0; i < game->box_count; i++) {
        if (slot_type(game, BOX[i].pos) == GOAL) {
            BOX[i].status = 0;
        } else
            BOX[i].status = 1;
        if (is_stuck(game, BOX[i].id) && BOX[i].status != 0)
            BOX[i].status = 2;
    }
    return;
}
