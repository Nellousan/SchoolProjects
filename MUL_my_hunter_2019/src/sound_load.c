/*
** EPITECH PROJECT, 2019
** sound load
** File description:
** 
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "my_hunter.h"

sound_t *load_sounds(char *folder)
{
    sound_t *sound = malloc(sizeof(sound_t));
    char *file_path = sp_cat("maps/", folder, "/audio.ogg");
    sound->music = sfMusic_createFromFile(file_path);
    sound->hitsound = sfMusic_createFromFile("sounds/hitsound.ogg");
    free(file_path);
    return sound;
}
