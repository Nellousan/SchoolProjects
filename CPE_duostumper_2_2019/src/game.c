/*
** EPITECH PROJECT, 2020
** game
** File description:
** c
*/

#include "stumper.h"
#include "my.h"

int game_loop(game_t *game)
{
    int player = 1;
    int g_o = 0;
    int check = 0;
    
    while (!g_o) {
        check = playing(game, player);
        while (check)
            check = playing(game, player);
        g_o = is_game_over(game);
        display_board(game);
        if (g_o)
            break;
        player = (player == 1) ? 2 : 1;
  
    }
    if (g_o && g_o != -1)
        my_printf("Congrats, player %c won!\n", (player == 1) ? P1 : P2);
    else
        my_printf("It's a tie, nobody wins.\n");
    return 0;
}
