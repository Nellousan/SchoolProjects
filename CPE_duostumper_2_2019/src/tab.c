/*
** EPITECH PROJECT, 2020
** tab maker
** File description:
** tab maker
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/stumper.h"
#include "a_malloc.h"

int **tab_maker(int x, int y)
{
    int **tab = a_malloc(sizeof(int *) * y | A_LIST(1));

    for (int i = 0; i < y; i++) {
        tab[i] = a_malloc(sizeof(int) * x | A_LIST(1));
	for (int j = 0; j < x; j++)
	    tab[i][j] = 0;
    }
    return (tab);
}

int play_tab(game_t *game, int play, int player)
{
    int limit = SIZE.y - 1;
    play -= 1;
    
    if (play < 0 || play >= SIZE.x)
        return (1);
    while (limit != -1) {
        if (BOARD[limit][play] == 0) {
            BOARD[limit][play] = (player == 1) ? 1 : BOARD[limit][play];
            BOARD[limit][play] = (player == 2) ? 2 : BOARD[limit][play];
            return (0);
        }
        else limit--;
    }
    return (1);
}

int check_str(char *str)
{
    int i = 0;

    while (str[i] != '\n') {
        if (str[i] < '0' || str[i] > '9')
	    return (1);
        i++;
    }
    return (0);
}

int waiting_value(game_t *game, int player)
{
    char *buffer = a_malloc(sizeof(char) * 2);
    size_t bufsize = 3;
    int value = 0;

    printf("%s", "Player ");
    if (player == 1)
        printf("%c ", P1);
    else printf("%c ", P2);
    printf("%s", ", where do you want to play: ");
    while (1) {
        getline(&buffer, &bufsize, stdin);
	if (check_str(buffer) == 1)
	    return (-1);
	value = atoi(buffer);
	break;
    }
    return (play_tab(game, value, player));
}

int playing(game_t *game, int player)
{
    int value = 0;
  
    value = waiting_value(game, player);
    if (value == -1 || value == 1)
        return (1);
    return (0);
}
