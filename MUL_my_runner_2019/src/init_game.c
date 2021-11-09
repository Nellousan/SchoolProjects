/*
** EPITECH PROJECT, 2020
** init game
** File description:
** 
*/

#include <stdlib.h>
#include <math.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my.h"
#include "my_runner.h"

int global_parameter_init(game_t *game)
{
    WINDOW = sfRenderWindow_create(VMODE, WINNAME, sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(WINDOW, 60);
    CLOCK = sfClock_create();
    G_STATUS = menu;
    sfMusic_setLoop(TS->music, sfTrue);
    sfMusic_setLoop(MAP->music, sfTrue);
    return 0;
}

int player_data_init(game_t *game)
{
    P_STATUS = idle;
    P_FRAME = 0;
    PLAYER->hp = PLAYER->max_hp;
    PLAYER->frame_time = sfClock_getElapsedTime(CLOCK);
    PLAYER->pos_time = PLAYER->frame_time;
    PLAYER->atk_time.microseconds = 0;
    PLAYER->dmg_time.microseconds = 0;
    PLAYER->facing = RIGHT;
    PLAYER->atk_cd = 0;
    PLAYER->atk_id = 0;
    P_POS = MAP->starting_pos;
    MAP->e_map = load_entity_map();
    return 0;
}
