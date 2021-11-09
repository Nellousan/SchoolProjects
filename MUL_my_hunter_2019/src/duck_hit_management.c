/*
** EPITECH PROJECT, 2019
** duck hit management
** File description:
** 
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "my_hunter.h"

int score_refresh(game_t *game, int accuracy)
{
    if (!accuracy) {
        PLAYER->combo = 0;
    } else {
        PLAYER->combo++;
        PLAYER->score += PLAYER->combo * accuracy;
    }
    if (PLAYER->combo > PLAYER->max_combo)
        PLAYER->max_combo = PLAYER->combo;
    PLAYER->accuracy = (100.f * (50.f * (float)PLAYER->fifty_c +
    100.f * (float)PLAYER->hundred_c + 300.f * (float)PLAYER->thundred_c) /
    (300.f * ((float)PLAYER->zero_c + (float)PLAYER->fifty_c +
    (float)PLAYER->hundred_c + (float)PLAYER->thundred_c)));
    return 0;
}

int duck_die_refresh(game_t *game)
{
    int offset = 0;
    for (int i = 0; DUCK_I.status != -1; i++) {
        if (TIME > DUCK_I.time_code + OD * 1.5 && DUCK_I.status != 2) {
            DUCK_I.status = 2;
            DUCK_I.score_tex = game->tex->hitmiss;
            offset = (TIME - (DUCK_I.time_code - AR)) * DUCK_I.speed / 1000;
            offset = (DUCK_I.slot[0] == 'r') ? -offset : offset;
            DUCK_I.die_pos.x = DUCK_I.anim_data->pos.x + offset;
            DUCK_I.die_pos.y = DUCK_I.anim_data->pos.y;
            PLAYER->zero_c++;
            score_refresh(game, 0);
        }
    }
    return 0;
}

int duck_hit_accuracy_setter(game_t *game, duck_t *duck)
{
    if (TIME <= DUCK_TC + OD && TIME >= DUCK_TC - OD) {
        duck->scored = 300;
        duck->score_tex = game->tex->hit300;
        PLAYER->thundred_c++;
    } else if (TIME <= DUCK_TC + OD * 1.3 && TIME >= DUCK_TC - OD * 1.3) {
        duck->scored = 100;
        duck->score_tex = game->tex->hit100;
        PLAYER->hundred_c++;
    } else if (TIME <= DUCK_TC + OD * 1.5 && TIME >= DUCK_TC - OD * 1.5) {
        duck->scored = 50;
        duck->score_tex = game->tex->hit50;
        PLAYER->fifty_c++;
    } else {
        duck->scored = 0;
        duck->score_tex = game->tex->hitmiss;
        PLAYER->zero_c++;
    }
    return duck->scored;
}

int duck_hit_management(game_t *game, duck_t *duck, int offset)
{
    int accuracy = duck_hit_accuracy_setter(game, duck);
    duck->die_pos.x = duck->anim_data->pos.x + offset;
    duck->die_pos.y = duck->anim_data->pos.y;
    return accuracy;
}

int check_duck_hit(game_t *game, duck_t *duck, sfMouseButtonEvent event)
{
    int offset = (TIME - (duck->time_code - AR)) * duck->speed / 1000;
    offset = (duck->slot[0] == 'r') ? -offset : offset;
    if (event.x >= duck->anim_data->pos.x + offset &&
    event.x <= duck->anim_data->pos.x + offset + 120 &&
    event.y >= duck->anim_data->pos.y &&
    event.y <= duck->anim_data->pos.y + 120) {
        duck->status = 2;
        int accuracy = duck_hit_management(game, duck, offset);
        sfMusic_stop(game->sound->hitsound);
        score_refresh(game, accuracy);
        if (accuracy)
            sfMusic_play(game->sound->hitsound);
        return 1;
    }
    return 0;
}
