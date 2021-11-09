/*
** EPITECH PROJECT, 2020
** load options
** File description:
** a
*/

#include <stdbool.h>
#include <getopt.h>
#include "my.h"
#include "tetris.h"

void key_setup(game_t *game, char c)
{
    switch (c) {
    case 'l':
        LEFT_KEY = optarg[0];
        break;
    case 'r':
        RIGHT_KEY = optarg[0];
        break;
    case 't':
        TURN_KEY = optarg[0];
        break;
    case 'd':
        DROP_KEY = optarg[0];
        break;
    case 'q':
        QUIT_KEY = optarg[0];
        break;
    case 'p':
        PAUSE_KEY = optarg[0];
        break;
    }
}

int options_load(game_t *game, int argc, char **argv)
{
    char c = '\0';
    while ((c = getopt(argc, argv, "L:l:r:t:d:q:p:wD")) != -1) {
        key_setup(game, c);
        switch (c) {
        case 'L':
            LEVEL = my_atoi(optarg);
            break;
        case 'w':
            WO_NEXT = true;
            break;
        case 'D':
            DBG = true;
        }
    }
    return 0;
}
