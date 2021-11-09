/*
** EPITECH PROJECT, 2020
** load hud
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

hud_t *hud_load(void)
{
    char *file = file_load("data/hud_data");
    char *file_c = file;
    hud_t *hud = malloc(sizeof(hud_t));
    hud->hud_sprsh = run_strcat(SPR_DIR, copy_until(&file, ';'));
    hud->h_bar_sprsh = run_strcat(SPR_DIR, copy_until(&file, ';'));
    hud->position = extract_vect(copy_until(&file, ';'));
    hud->hud_tex = sfTexture_createFromFile(hud->hud_sprsh, NULL);
    hud->h_bar_tex = sfTexture_createFromFile(hud->h_bar_sprsh, NULL);
    hud->hud_spr = sprite_create(hud->hud_tex, NULL);
    hud->h_bar_spr = sprite_create(hud->h_bar_tex, NULL);
    free(file_c);
    return hud;
}
