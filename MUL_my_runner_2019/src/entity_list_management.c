/*
** EPITECH PROJECT, 2020
** entity_list_management	
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

int e_list_management(game_t *game)
{
    for (int i = 0; E_MAP[i] != NULL; i++) {
        if (is_in_loading_range(game, (int)E_MAP[i]->pos.x) &&
        E_MAP[i]->status == 0) {
            E_MAP[i]->status = 1;
            obj_create(game, E_MAP[i]->id, E_MAP[i]);
        }
    }
    return 0;
}
