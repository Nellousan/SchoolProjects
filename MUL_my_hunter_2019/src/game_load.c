/*
** EPITECH PROJECT, 2019
** loading functions
** File description:
** 
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "my_hunter.h"

sfVideoMode *mode_init(unsigned int w, unsigned int h, unsigned int bpp)
{
    sfVideoMode *mode = malloc(sizeof(sfVideoMode));
    mode->width = w;
    mode->height = h;
    mode->bitsPerPixel = bpp;
    return mode;
}

char *load_raw_map(char *folder)
{
    char *buffer = malloc(sizeof(char) * 10240);
    char *file_path = sp_cat("maps/", folder, "/beatmap");
    int fd = open(file_path, O_RDONLY);
    if (fd == -1) {
        free(buffer);
        my_putstr("Error: Invalid map name.\n");
        return NULL;
    }
    int size = read(fd, buffer, 10240);
    buffer[size] = '\0';
    char *buffer2 = my_strdup(buffer);
    free(buffer);
    return buffer2;
}

player_t *player_data_init(void)
{
    player_t *player = malloc(sizeof(player_t));
    player->score = 0;
    player->combo = 0;
    player->max_combo = 0;
    player->accuracy = 100;
    player->zero_c = 0;
    player->fifty_c = 0;
    player->hundred_c = 0;
    player->thundred_c = 0;
    return player;
}

int beatmap_info_init(game_t *game, int i, char *raw_map)
{
    AR = char_to_int(copy_until(raw_map, ','));
    for (i = 0; raw_map[i] != ','; i++);
    OD = char_to_int(copy_until(raw_map + ++i, ';'));
    for (; raw_map[i] != ';'; i++);
    BPM = char_to_int(copy_until(raw_map + ++i, ':'));
    for (; raw_map[i] != ':'; i++);
    BPM_OFFSET = char_to_int(copy_until(raw_map + ++i, '\n'));
    for (; raw_map[i] != '\n'; i++);
    return i;
}

game_t *load_game(char *folder)
{
    game_t *game = malloc(sizeof(game_t));
    char *raw_map = load_raw_map(folder);
    int i = 0;
    if (raw_map == NULL) {
        free(game);
        return NULL;
    }
    VMODE = mode_init(1700, 1000, 32);
    game->status = 0;
    i = beatmap_info_init(game, i, raw_map);
    game->duck = load_ducks(game, raw_map + ++i);
    IMG = load_images();
    TEX = load_tex(game);
    SPR = load_sprites(game);
    game->sound = load_sounds(folder);
    PLAYER = player_data_init();
    FRAMEBUFFER = framebuffer_create(VMODE->width, VMODE->height);
    return game;
}
