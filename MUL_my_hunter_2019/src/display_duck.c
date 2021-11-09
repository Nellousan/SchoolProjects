/*
** EPITECH PROJECT, 2019
** duck display funcs
** File description:
** 
*/

#include <stdlib.h>
#include <math.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "my_hunter.h"

sfSprite *sprite_create(sfTexture *tex)
{
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, tex, sfTrue);
    return sprite;
}

int display_apprsq(game_t *game, duck_t *duck, sfVector2f draw_pos)
{
    sfSprite *appr_s = sprite_create(game->tex->appr_tex);
    float scale_val = (float) 3 * (duck->time_code - TIME) / AR + 1;
    sfVector2f scale = sf_vector_init(scale_val, scale_val);
    sfSprite_setScale(appr_s, scale);
    float px_offset = (120 * scale_val - 120) / 2;
    sfVector2f app_draw_pos = sf_vector_init(draw_pos.x - px_offset,
    draw_pos.y - px_offset);
    sfSprite_setPosition(appr_s, app_draw_pos);
    sfRenderWindow_drawSprite(game->window, appr_s, NULL);
    sfSprite_destroy(appr_s);
    return 0;
}

int display_duck(game_t *game, duck_t *duck)
{
    int px_offset = (TIME - (duck->time_code - AR)) * duck->speed / 1000;
    sfSprite *duck_s = sprite_create(game->tex->duck_tex);
    px_offset = (duck->slot[0] == 'r') ? -px_offset : px_offset;
    sfVector2f draw_pos = sf_vector_init(duck->anim_data->pos.x + px_offset,
    duck->anim_data->pos.y);
    sfSprite_setPosition(duck_s, draw_pos);
    sfRenderWindow_drawSprite(game->window, duck_s, NULL);
    if (TIME < duck->time_code)
        display_apprsq(game, duck, draw_pos);
    sfSprite_destroy(duck_s);
    return 0;
}

int draw_floating_score(game_t *game, duck_t *duck)
{
    sfSprite *score = sprite_create(duck->score_tex);
    sfColor opacity = sf_color_init(255, 255, 255,
    255 - (TIME - duck->time_code) * 255 / 500);
    sfSprite_setColor(score, opacity);
    sfSprite_setPosition(score, duck->die_pos);
    sfRenderWindow_drawSprite(game->window, score, NULL);
    return 0;
}

int floating_scores_management(game_t *game)
{
    for (int i = 0; DUCK_I.status != -1; i++) {
        if (DUCK_I.status == 2 && TIME - DUCK_I.time_code < 500)
            draw_floating_score(game, &DUCK_I);
    }
    return 0;
}
