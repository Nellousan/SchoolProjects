/*
** EPITECH PROJECT, 2019
** second part of displaying scores
** File description:
** 
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

void rs_draw_scores_number(game_t *game, sfSprite *spr, sfVector2f vect)
{
    sfSprite_setScale(spr, sf_vector_init(0.5, 0.5));
    sfSprite_setPosition(spr, vect);
    sfRenderWindow_drawSprite(WINDOW, spr, NULL);
    sfSprite_setScale(spr, sf_vector_init(1, 1));
    return;
}

void rs_draw_thundred(game_t *game)
{
    char *thundred = my_int_to_char(PLAYER->thundred_c);
    sf_draw_sprite(game, SPR->hit300,
    sf_vector_init(XOFF + 75, 305 + YOFF));
    rs_draw_scores_number(game, SPR->number[11],
    sf_vector_init(XOFF + 230, YOFF + 342));
    for (int i = 0; i < my_strlen(thundred); i++) {
        rs_draw_scores_number(game, SPR->number[DEC(thundred[i])],
        sf_vector_init(XOFF + 258 + 24 * i, YOFF + 342));
    }
    free(thundred);
    return;
}

void rs_draw_hundred(game_t *game)
{
    char *hundred = my_int_to_char(PLAYER->hundred_c);
    sf_draw_sprite(game, SPR->hit100,
    sf_vector_init(XOFF + 75, YOFF + 455));
    rs_draw_scores_number(game, SPR->number[11],
    sf_vector_init(XOFF + 230, YOFF + 492));
    for (int i = 0; i < my_strlen(hundred); i++) {
        rs_draw_scores_number(game, SPR->number[DEC(hundred[i])],
        sf_vector_init(XOFF + 258 + 24 * i, YOFF + 492));
    }
    free(hundred);
    return;
}

void rs_draw_fifty(game_t *game)
{
    char *fifty = my_int_to_char(PLAYER->fifty_c);
    sf_draw_sprite(game, SPR->hit50,
    sf_vector_init(XOFF + 381, 305 + YOFF));
    rs_draw_scores_number(game, SPR->number[11],
    sf_vector_init(XOFF + 536, YOFF + 342));
    for (int i = 0; i < my_strlen(fifty); i++) {
        rs_draw_scores_number(game, SPR->number[DEC(fifty[i])],
        sf_vector_init(XOFF + 560 + 24 * i, YOFF + 342));
    }
    free(fifty);
    return;
}

void rs_draw_miss(game_t *game)
{
    char *miss = my_int_to_char(PLAYER->zero_c);
    sf_draw_sprite(game, SPR->hitmiss,
    sf_vector_init(XOFF + 381, YOFF + 455));
    rs_draw_scores_number(game, SPR->number[11],
    sf_vector_init(XOFF + 536, YOFF + 492));
    for (int i = 0; i < my_strlen(miss); i++) {
        rs_draw_scores_number(game, SPR->number[DEC(miss[i])],
        sf_vector_init(XOFF + 560 + 24 * i, YOFF + 492));
    }
    free(miss);
    return;
}
