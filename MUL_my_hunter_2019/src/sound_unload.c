/*
** EPITECH PROJECT, 2019
** unload sounds
** File description:
** 
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <fcntl.h>
#include "my.h"
#include "my_hunter.h"

void unload_sounds(sound_t *sound)
{
    sfMusic_destroy(sound->music);
    sfMusic_destroy(sound->hitsound);
    free(sound);
    my_putstr("Sounds successfully unloaded.\n");
    return;
}
