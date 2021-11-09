/*
** EPITECH PROJECT, 2019
** checking if game is over
** File description:
** 
*/

#include <stdlib.h>
#include <curses.h>
#include "my.h"
#include "my_sokoban.h"

int get_return_status(game_t *game)
{
    for (int i = 0; i < BOX_C; i++)
        if (BOX[i].status == 2)
            return 1;
    return 0;
}

int is_all_box_stuck(game_t *game)
{
    for (int i = 0; i < BOX_C; i++)
        if (BOX[i].status != 2)
            return 0;
    return 1;
}

int is_all_box_clear(game_t *game)
{
    for (int i = 0; i < BOX_C; i++)
        if (BOX[i].status != 0)
            return 0;
    return 1;
}

int is_game_over(game_t *game)
{
    if (is_all_box_clear(game))
        return 1;
    if (is_all_box_stuck(game))
        return 1;
    return 0;
}
