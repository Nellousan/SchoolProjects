/*
** EPITECH PROJECT, 2019
** game load main
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

sfVideoMode vmode_init(int w, int h, int bpp)
{
    sfVideoMode mode;
    mode.width = w;
    mode.height = h;
    mode.bitsPerPixel = bpp;
    return mode;
}

keyp_t *key_init(sfKeyCode code, void (*fptr)(game_t *game))
{
    keyp_t *key = malloc(sizeof(keyp_t));
    key->code = code;
    key->fptr = fptr;
    return key;
}

keyp_t **key_load(void)
{
    char *file = file_load("data/key_data");
    char *file_c = file;
    keyp_t **key = malloc(sizeof(key_t *) * 4);
    key[0] = key_init(char_to_int(copy_until(&file, ';')), &key_left);
    key[1] = key_init(char_to_int(copy_until(&file, ';')), &key_right);
    key[2] = key_init(char_to_int(copy_until(&file, ';')), &key_down);
    key[3] = key_init(char_to_int(copy_until(&file, ';')), &jump_management);
    free(file_c);
    return key;
}

game_t *game_load(char *dirpath)
{
    game_t *game = malloc(sizeof(game_t));
    E_LIST = e_list_load();
    PLAYER = player_load();
    MAP = map_load(dirpath);
    if (MAP == NULL)
        return NULL;
    TEX = texture_load(game);
    SPR = sprite_load(game);
    KEY = key_load();
    G_OVER = game_over_load();
    TS = title_screen_load();
    END = end_screen_load();
    HUD = hud_load();
    VMODE = vmode_init(1200, 768, 32);
    return game;
}
