/*
** EPITECH PROJECT, 2019
** game loop
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

int is_game_over(game_t *game)
{
    if (PLAYER->hp <= 0) {
        G_STATUS = death;
        P_STATUS = dying;
        P_FRAME = 0;
    }
    return 0;
}

int game_loop(game_t *game)
{
    player_data_init(game);
    obj_init(game);
    sfMusic_play(MAP->music);
    while (sfRenderWindow_isOpen(WINDOW) && G_STATUS == stage) {
        TIME = sfClock_getElapsedTime(CLOCK);
        event_management(game);
        e_list_management(game);
        player_data_update(game);
        player_attack_hit_management(game);
        obj_data_update(game);
        display_management(game);
        is_game_over(game);
    }
    sfMusic_stop(MAP->music);
    return 0;
}
