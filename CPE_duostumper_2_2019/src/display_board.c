/*
** EPITECH PROJECT, 2020
** display management
** File description:
** c
*/

#include "stumper.h"
#include "my.h"

static int print_plus_line(game_t *game)
{
    for (int i = 0; i < SIZE.x + 2; i++)
        my_printf("+");
    my_printf("\n");
    return 0;
}

static int print_board_line(game_t *game, int *b_line)
{
    my_printf("|");
    for (int i = 0; i < SIZE.x; i++) {
        if (b_line[i] == 1)
            my_printf("%c", P1);
        if (b_line[i] == 2)
            my_printf("%c", P2);
        if (b_line[i] == 3)
            my_printf("%c", REF);
        if (b_line[i] == 0)
            my_printf(".");
    }
    my_printf("|\n");
    return 0;
}

int display_board(game_t *game)
{
    print_plus_line(game);
    for (int i = 0; i < SIZE.y; i++)
        print_board_line(game, BOARD[i]);
    print_plus_line(game);
    return 0;
}
