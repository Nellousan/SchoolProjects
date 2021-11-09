/*
** EPITECH PROJECT, 2019
** unloading ducks
** File description:
** 
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <fcntl.h>
#include "my.h"
#include "my_hunter.h"

void unload_ducks(duck_t *duck)
{
    int i = 0;
    for (; duck[i].status != -1; i++) {
        free(duck[i].anim_data);
    }
    free(duck);
    my_putstr("Ducks successfully unloaded.\n");
    return;
}
