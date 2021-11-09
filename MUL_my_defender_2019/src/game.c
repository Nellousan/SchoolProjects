/*
** EPITECH PROJECT, 2020
** game_loop.c
** File description:
** a
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include "defender.h"
#include "a_malloc.h"

int init_obj(game_t *game)
{
    for (int i = 0; i < 32; i++) {
        TOWER[i].obj_status = 0;
        TOWER[i].focus = -1;
        TOWER[i].last_attack = TIME;
        MOB[i].obj_status = 0;
    }
    return 0;
}

int game_loop(game_t *game)
{
    sfTime time;
    sfTime move;

    CLOCK = sfClock_create();
    init_obj(game);
    create_enemy(game);
    move.microseconds = 0;
    while (sfRenderWindow_isOpen(WINDOW)) {
        time = TIME;
        event_management(game);
        tower_management(game);
        reset_mob(game);
        if (move.microseconds == 0 ||
        time.microseconds - move.microseconds >= 30000) {
            move_mob(game);
            move = time;
        }
        display_management(game);
    }
    return 0;
}
