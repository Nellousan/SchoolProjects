/*
** EPITECH PROJECT, 2020
** navystructs
** File description:
** a
*/

#ifndef NAVY_STRUCTS
#define NAVY_STRUCTS

#include <sys/types.h>

/************** STRUCTS ***************/

enum boat {
    destroyer,
    submarine,
    battleship,
    cruiser
};

typedef struct vect {
    int x;
    int y;
}vect_t;

typedef struct mapnode {
    vect_t pos;
    int ship;
    int hit;
}mapn_t;

typedef struct boats {
    int destr_c;
    int sub_c;
    int btlship_c;
    int cruiser_c;
    vect_t destroyer[2];
    vect_t submarine[2];
    vect_t battleship[2];
    vect_t cruiser[2];
}boats_t;

typedef struct game {
    boats_t *boats;
    mapn_t **map;
    mapn_t **tmap;
    int player;
    pid_t e_pid;
    int return_status;
}game_t;

/**************************************/

#endif
