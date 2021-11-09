/*
** EPITECH PROJECT, 2020
** end screen load
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

end_t *end_screen_load(void)
{
    char *file = file_load("data/end_screen_data");
    char *file_c = file;
    end_t *end = malloc(sizeof(game_over_t));
    end->bg_sprsh = run_strcat(SPR_DIR, copy_until(&file, ';'));
    end->ts_sprsh = run_strcat(SPR_DIR, copy_until(&file, ';'));
    end->retry_sprsh = run_strcat(SPR_DIR, copy_until(&file, ';'));
    end->ts_rect = extract_rect(copy_until(&file, ';'));
    end->retry_rect = extract_rect(copy_until(&file, ';'));
    end->bg_tex = sfTexture_createFromFile(end->bg_sprsh, NULL);
    end->ts_tex = sfTexture_createFromFile(end->ts_sprsh, NULL);
    end->retry_tex = sfTexture_createFromFile(end->retry_sprsh, NULL);
    end->bg_spr = sprite_create(end->bg_tex, NULL);
    end->ts_spr = sprite_create(end->ts_tex, NULL);
    end->retry_spr = sprite_create(end->retry_tex, NULL);
    end->music = sfMusic_createFromFile(run_strcat(
    "song/", copy_until(&file, ';')));
    free(file_c);
    return end;
}
