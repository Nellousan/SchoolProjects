/*
** EPITECH PROJECT, 2019
** display scores on result screen
** File description:
** 
*/

#include <stdlib.h>
#include <math.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "my_hunter.h"

void rs_draw_score(game_t *game)
{
    char *score = my_int_to_char(PLAYER->score);
    for (int i = 0; i < my_strlen(score); i++) {
        sf_draw_sprite(game, SPR->number[DEC(score[i])],
        sf_vector_init(XOFF + 128 + 48 * i, YOFF + YOFF / 4 + 10));
    }
    free(score);
    return;
}

void rs_draw_max_combo(game_t *game)
{
    char *combo = my_revstrdup(my_int_to_char(PLAYER->max_combo));
    sf_draw_sprite(game, SPR->number[11],
    sf_vector_init(VMODE->width - XOFF - 160, YOFF + YOFF / 4 + 10));
    for (int i = 0; i < my_strlen(combo); i++) {
        sf_draw_sprite(game, SPR->number[DEC(combo[i])],
        sf_vector_init(VMODE->width - XOFF - 160 - 48 * (i + 1),
        YOFF + YOFF / 4 + 10));
    }
    free(combo);
    return;
}

void rs_draw_accuracy(game_t *game)
{
    char *acc;
    int i = 0;
    int j = 0;
    int chara = 0;
    if (PLAYER->accuracy == 0)
        acc = my_strdup("000");
    else
        acc = my_revstrdup(my_int_to_char(PLAYER->accuracy * 100));
    for (; i < my_strlen(acc) + 2; i++, j++) {
        chara = display_accuracy_chara_selector(acc, i, &j);
        sf_draw_sprite(game, SPR->number[chara],
        sf_vector_init(VMODE->width - XOFF - 160 - 48 * i,
        VMODE->height / 2 + 64));
    }
    free(acc);
    return;
}
