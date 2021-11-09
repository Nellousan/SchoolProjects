/*
** EPITECH PROJECT, 2020
** game_over_load	
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

game_over_t *game_over_load(void)
{
    char *file = file_load("data/game_over_data");
    char *file_c = file;
    game_over_t *g_over = malloc(sizeof(game_over_t));
    g_over->bg_sprsh = run_strcat(SPR_DIR, copy_until(&file, ';'));
    g_over->ts_sprsh = run_strcat(SPR_DIR, copy_until(&file, ';'));
    g_over->retry_sprsh = run_strcat(SPR_DIR, copy_until(&file, ';'));
    g_over->ts_rect = extract_rect(copy_until(&file, ';'));
    g_over->retry_rect = extract_rect(copy_until(&file, ';'));
    g_over->bg_tex = sfTexture_createFromFile(g_over->bg_sprsh, NULL);
    g_over->ts_tex = sfTexture_createFromFile(g_over->ts_sprsh, NULL);
    g_over->retry_tex = sfTexture_createFromFile(g_over->retry_sprsh, NULL);
    g_over->bg_spr = sprite_create(g_over->bg_tex, NULL);
    g_over->ts_spr = sprite_create(g_over->ts_tex, NULL);
    g_over->retry_spr = sprite_create(g_over->retry_tex, NULL);
    g_over->music = sfMusic_createFromFile(run_strcat(
    "song/", copy_until(&file, ';')));
    free(file_c);
    return g_over;
}
