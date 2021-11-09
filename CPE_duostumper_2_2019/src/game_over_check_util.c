/*
** EPITECH PROJECT, 2020
** game over
** File description:
** check
*/

#include "stumper.h"

int check_diag1(game_t *game, vect_t pos)
{
    int res1 = 0;
    int res2 = 0;
    int res3 = 0;
    res1 = (BOARD[pos.y + 1][pos.x - 1] == BOARD[pos.y][pos.x]) ? 1 : 0;
    res2 = (BOARD[pos.y + 2][pos.x - 2] == BOARD[pos.y][pos.x]) ? 1 : 0;
    res3 = (BOARD[pos.y + 3][pos.x - 3] == BOARD[pos.y][pos.x]) ? 1 : 0;
    if (res1 & res2 & res3) {
        BOARD[pos.y][pos.x] = 3;
        BOARD[pos.y + 1][pos.x - 1] = 3;
        BOARD[pos.y + 2][pos.x - 2] = 3;
        BOARD[pos.y + 3][pos.x - 3] = 3;
    }
    return res1 & res2 & res3;
}

int check_diag2(game_t *game, vect_t pos)
{
    int res1 = 0;
    int res2 = 0;
    int res3 = 0;
    res1 = (BOARD[pos.y + 1][pos.x + 1] == BOARD[pos.y][pos.x]) ? 1 : 0;
    res2 = (BOARD[pos.y + 2][pos.x + 2] == BOARD[pos.y][pos.x]) ? 1 : 0;
    res3 = (BOARD[pos.y + 3][pos.x + 3] == BOARD[pos.y][pos.x]) ? 1 : 0;
    if (res1 & res2 & res3) {
        BOARD[pos.y][pos.x] = 3;
        BOARD[pos.y + 1][pos.x + 1] = 3;
        BOARD[pos.y + 2][pos.x + 2] = 3;
        BOARD[pos.y + 3][pos.x + 3] = 3;
    }
    return res1 & res2 & res3;
}

int check_vertical(game_t *game, vect_t pos)
{
    int res1 = 0;
    int res2 = 0;
    int res3 = 0;
    res1 = (BOARD[pos.y + 1][pos.x] == BOARD[pos.y][pos.x]) ? 1 : 0;
    res2 = (BOARD[pos.y + 2][pos.x] == BOARD[pos.y][pos.x]) ? 1 : 0;
    res3 = (BOARD[pos.y + 3][pos.x] == BOARD[pos.y][pos.x]) ? 1 : 0;
    if (res1 & res2 & res3) {
        BOARD[pos.y][pos.x] = 3;
        BOARD[pos.y + 1][pos.x] = 3;
        BOARD[pos.y + 2][pos.x] = 3;
        BOARD[pos.y + 3][pos.x] = 3;
    }
    return res1 & res2 & res3;
}

int check_horizontal(game_t *game, vect_t pos)
{
    int res1 = 0;
    int res2 = 0;
    int res3 = 0;
    res1 = (BOARD[pos.y][pos.x + 1] == BOARD[pos.y][pos.x]) ? 1 : 0;
    res2 = (BOARD[pos.y][pos.x + 2] == BOARD[pos.y][pos.x]) ? 1 : 0;
    res3 = (BOARD[pos.y][pos.x + 3] == BOARD[pos.y][pos.x]) ? 1 : 0;
    if (res1 & res2 & res3) {
        BOARD[pos.y][pos.x] = 3;
        BOARD[pos.y][pos.x + 1] = 3;
        BOARD[pos.y][pos.x + 2] = 3;
        BOARD[pos.y][pos.x + 3] = 3;
    }
    return res1 & res2 & res3;
}
