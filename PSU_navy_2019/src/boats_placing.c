/*
** EPITECH PROJECT, 2020
** boat placing
** File description:
** aa
*/

#include <stdbool.h>
#include "navy.h"
#include "my.h"

static bool p_btwn_2_p(vect_t c1, vect_t c2, vect_t p)
{
    int dxc = p.x - c1.x;
    int dyx = p.y - c1.y;
    int dxl = c2.x - c1.x;
    int dyl = c2.y - c1.y;
    int cross = (dxc * dyl) - (dyx * dxl);
    if (cross != 0)
        return false;
    if (ABS(dxl) >= ABS(dyl))
        return dxl > 0 ?
        c1.x <= p.x && p.x <= c2.x :
        c2.x <= p.x && p.x <= c1.x;
    else
        return dyl > 0 ?
        c1.y <= p.y && p.y <= c2.y :
        c2.y <= p.y && p.y <= c2.y;
}

int boats_placing(game_t *game)
{
    for (int i = 0; i < 64; i++) {
        if (p_btwn_2_p(DESTR[0], DESTR[1], MAP[i]->pos) == true) {
            if (MAP[i]->ship != 0)
                return 0;
            MAP[i]->ship = 2;
        } if (p_btwn_2_p(SUB[0], SUB[1], MAP[i]->pos) == true) {
            if (MAP[i]->ship != 0)
                return 0;
            MAP[i]->ship = 3;
        } if (p_btwn_2_p(BTLSHIP[0], BTLSHIP[1], MAP[i]->pos) == true) {
            if (MAP[i]->ship != 0)
                return 0;
            MAP[i]->ship = 4;
        } if (p_btwn_2_p(CRUISER[0], CRUISER[1], MAP[i]->pos) == true) {
            if (MAP[i]->ship != 0)
                return 0;
            MAP[i]->ship = 5;
        }
    }
    return 1;
}
