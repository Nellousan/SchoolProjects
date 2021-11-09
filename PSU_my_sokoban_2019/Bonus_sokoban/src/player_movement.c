/*
** EPITECH PROJECT, 2019
** player movement
** File description:
** 
*/

#include <stdlib.h>
#include <curses.h>
#include "my.h"
#include "my_sokoban.h"

int can_move(game_t *game, vect_t vect)
{
    if (slot_type(game, vect) == WALL)
        return 0;
    return 1;
}

int is_box(game_t *game, vect_t vect)
{
    for (int i = 0; i < game->box_count; i++)
        if (BOX[i].pos.x == vect.x && BOX[i].pos.y == vect.y)
            return i;
    return -1;
}

int box_move(game_t *game, int id, vect_t dir)
{
    vect_t m_pos = vect_add(BOX[id].pos, dir);
    if (slot_type(game, m_pos) == WALL)
        return 0;
    else if (is_box(game, m_pos) != -1)
        return 0;
    BOX[id].pos = m_pos;
    return 1;
}

void player_move(game_t *game, vect_t vect)
{
    int id = is_box(game, vect);
    if (id != -1)
        if (!box_move(game, id, vect_sub(vect, P_POS)))
            return;
    if (!can_move(game, vect))
        return;
    P_POS = vect;
    return;
}
