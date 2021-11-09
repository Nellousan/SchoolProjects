/*
** EPITECH PROJECT, 2020
** title screen load	
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

ts_t *title_screen_load(void)
{
    char *file = file_load("data/title_screen_data");
    char *file_c = file;
    ts_t *ts = malloc(sizeof(ts_t));
    ts->bg_sprsh = run_strcat(SPR_DIR, copy_until(&file, ';'));
    ts->quit_sprsh = run_strcat(SPR_DIR, copy_until(&file, ';'));
    ts->start_sprsh = run_strcat(SPR_DIR, copy_until(&file, ';'));
    ts->bg_tex = sfTexture_createFromFile(ts->bg_sprsh, NULL);
    ts->quit_tex = sfTexture_createFromFile(ts->quit_sprsh, NULL);
    ts->start_tex = sfTexture_createFromFile(ts->start_sprsh, NULL);
    ts->bg_spr = sprite_create(ts->bg_tex, NULL);
    ts->quit_spr = sprite_create(ts->quit_tex, NULL);
    ts->start_spr = sprite_create(ts->start_tex, NULL);
    ts->start_rect = extract_rect(copy_until(&file, ';'));
    ts->quit_rect = extract_rect(copy_until(&file, ';'));
    ts->music = sfMusic_createFromFile(run_strcat(
    "song/", copy_until(&file, ';')));
    free(file_c);
    return ts;
}
