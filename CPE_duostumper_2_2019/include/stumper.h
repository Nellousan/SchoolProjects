/*
** EPITECH PROJECT, 2020
** stumper
** File description:
** h
*/

#ifndef STUMPER_H
#define STUMPER_H

typedef struct vect {
    int x;
    int y;
}vect_t;

typedef struct game {
    int **board;
    char p1;
    char p2;
    char a;
    vect_t size;
}game_t;

#define BOARD game->board
#define P1 game->p1
#define P2 game->p2
#define REF game->a
#define SIZE game->size

#define VECT(x, y) (vect_t){(x), (y)}

game_t *game_load(int argc, char **argv);
int game_loop(game_t *game);
int **tab_maker(int x, int y);
int is_game_over(game_t *game);
int display_board(game_t *game);
int playing(game_t *game, int player);
int check_diag1(game_t *game, vect_t pos);
int check_diag2(game_t *game, vect_t pos);
int check_vertical(game_t *game, vect_t pos);
int check_horizontal(game_t *game, vect_t pos);

#endif
