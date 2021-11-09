/*
** EPITECH PROJECT, 2019
** beat duck textures
** File description:
** selecting the right texture for ducks
*/

#include <stdlib.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include "my.h"
#include "my_hunter.h"

int duck_beat_texture_selector(game_t *game)
{
    double y = (double) 1000 / (BPM / 60) / 2;
    double tex_sel = (10 * exp(3.4 * cos((TIME - BPM_OFFSET) * M_PI / y)));
    int frame = 0;
    if (tex_sel >= 250)
        frame = 4;
    else if (tex_sel < 250 && tex_sel >= 200)
        frame = 3;
    else if (tex_sel < 200 && tex_sel >= 140)
        frame = 2;
    else if (tex_sel < 140 && tex_sel >= 80)
        frame = 1;
    return frame;
}

int duck_beat_texture_management(game_t *game)
{
    int frame = duck_beat_texture_selector(game);
    sfIntRect rect = {120 * frame, 0, 120, 120};
    sfTexture_destroy(game->tex->duck_tex);
    TEX->duck_tex = sfTexture_createFromImage(IMG->duck_img, &rect);
    return 0;
}
