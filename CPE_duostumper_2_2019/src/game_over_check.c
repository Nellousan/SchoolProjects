/*
** EPITECH PROJECT, 2020
** game over
** File description:
** check
*/

#include "stumper.h"

static int check_sender(game_t *game, vect_t pos)
{
    if (pos.x > 3 && (SIZE.y) - pos.y > 3)
        if (check_diag1(game, pos))
            return BOARD[pos.y][pos.x];
    if ((SIZE.x) - pos.x > 3 && (SIZE.y) - pos.y > 3)
        if (check_diag2(game, pos))
            return BOARD[pos.y][pos.x];
    if ((SIZE.x) - pos.x > 3)
        if (check_horizontal(game, pos))
            return BOARD[pos.y][pos.x];
    if ((SIZE.y) - pos.y > 3)
        if (check_vertical(game, pos))
            return BOARD[pos.y][pos.x];
    return 0;
}

static int check_is_full(game_t *game)
{
    int b_size = (SIZE.x - 1) * (SIZE.y - 1);
    for (int i = 0; i < b_size; i++)
        if (BOARD[i / (SIZE.y - 1)][i % (SIZE.x - 1)] == 0)
            return 0;
    return 1;
}

int is_game_over(game_t *game)
{
    int b_size = (SIZE.x - 1) * (SIZE.y - 1);
    int res;
    vect_t pos;
    for (int i = 0; i < b_size; i++) {
        res = 0;
        pos = VECT(i % (SIZE.y - 1), i / (SIZE.y - 1));
        if (BOARD[pos.y][pos.x])
            res = check_sender(game, pos);
        if (res) {
            return res;
        }
    }
    if (check_is_full(game))
        return -1;
    return 0;
}
