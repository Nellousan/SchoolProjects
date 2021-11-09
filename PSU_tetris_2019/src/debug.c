/*
** EPITECH PROJECT, 2020
** debug
** File description:
** c
*/

#include <curses.h>
#include <stdbool.h>
#include "tetris.h"

static int count_tetriminos(game_t *game)
{
    int i = 0;
    for (; TETRI[i] != NULL; i++);
    return i;
}

static void print_tetriminos(game_t *game)
{
    printw("Tetriminos :  %d\n", count_tetriminos(game));
    for (int i = 0; TETRI[i] != NULL; i++) {
        printw("Tetrimino :  Name %s :  ", TETRI[i]->name);
        printw("Size %d*%d :  ", TETRI[i]->size.x, TETRI[i]->size.y);
        printw("Color %d :\n", TETRI[i]->color);
        for (int j = 0; TETRI[i]->body[j] != NULL; j++)
            printw("%s\n", TETRI[i]->body[j]);
    }
    return;
}

static void print_options(game_t *game)
{
    printw("Key Left :  %c\n", LEFT_KEY);
    printw("Key Right :  %c\n", RIGHT_KEY);
    printw("Key Turn :  %c\n", TURN_KEY);
    printw("Key Drop :  %c\n", DROP_KEY);
    printw("Key Quit :  %c\n", QUIT_KEY);
    printw("Key Pause :  %c\n", PAUSE_KEY);
    printw("Next :  %s\n", (WO_NEXT) ? "No" : "Yes");
    printw("Level :  %d\n", LEVEL);
    printw("Size :  %d*%d\n", MAP_SIZE.y, MAP_SIZE.x);
    return;
}

void debug(game_t *game)
{
    printw("*** DEBUG MODE ***\n");
    print_options(game);
    print_tetriminos(game);
    printw("Press any key to start Tetris\n");
    while (!getch()) {}
    return;
}
