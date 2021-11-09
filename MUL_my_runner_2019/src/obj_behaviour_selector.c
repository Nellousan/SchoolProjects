/*
** EPITECH PROJECT, 2020
** behaviour slector
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

int obj_behaviour_selector(game_t *game, obj_t *obj)
{
    if (obj->obj_status != 1)
        return 0;
    switch (obj->behaviour) {
    case 0:
        behaviour_one_management(game, obj);
        break;
    case 1:
        behaviour_two_management(game, obj);
        break;
    }
    return 0;
}
