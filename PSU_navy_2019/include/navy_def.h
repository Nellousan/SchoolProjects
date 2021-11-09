/*
** EPITECH PROJECT, 2020
** navy def
** File description:
** def
*/

#ifndef NAVY_DEF
#define NAVY_DEF

#include "navy_s.h"

/************** DEFINES ***************/

#define UNUSED __attribute__((unused))
#define RETURN_STATUS game->return_status
#define PLAYER game->player
#define E_PID game->e_pid
#define BOATS game->boats
#define DESTR game->boats->destroyer
#define SUB game->boats->submarine
#define BTLSHIP game->boats->battleship
#define CRUISER game->boats->cruiser
#define MAP game->map
#define TMAP game->tmap
#define ABS(x) (((x) < 0) ? -(x) : (x))
#define VECT(x, y) (vect_t){(x), (y)}
#define DEC(x) ((x) - '0')
#define GET_CONTINUE(x) (((x) & 0xff000000) >> 24)
#define GET_ITERATION(x) (((x) & 0x00ff0000) >> 16)
#define GET_HITPOSX(x) (((x) & 0x0000ff00) >> 8)
#define GET_HITPOSY(x) (((x) & 0x000000ff) >> 0)
#define SET_CONTINUE(x) ((x) << 24)
#define ADD_CONTINUE(x) ((x) += (1 << 24))
#define ADD_ITERATION(x) ((x) += (1 << 16))
#define ADD_HITPOSX(x) ((x) += (1 << 8))
#define ADD_HITPOSY(x) ((x) += (1 << 0))

/**************************************/

#endif
