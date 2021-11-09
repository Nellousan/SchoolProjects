/*
** EPITECH PROJECT, 2019
** score display during games
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

int display_score(game_t *game)
{
    char *score = my_int_to_char(PLAYER->score);
    for (int i = 0; i < my_strlen(score); i++) {
        sf_draw_sprite(game, SPR->number[DEC(score[i])],
        sf_vector_init(XOFF + i * 46, YOFF - 84));
    }
    free(score);
    return 0;
}

int display_accuracy_chara_selector(char *acc, int i, int *j)
{
    int chara;
    if (i == 0) {
        chara = 12;
        (*j)--;
    } else if (i == 3) {
        chara = 10;
        (*j)--;
    } else {
        chara = DEC(acc[(*j)]);
    }
    return chara;
}

int display_accuracy(game_t *game)
{
    char *acc;
    int j = 0;
    int chara;
    if (PLAYER->accuracy == 0)
        acc = my_strdup("000");
    else
        acc = my_revstrdup(my_int_to_char(PLAYER->accuracy * 100));
    for (int i = 0; i < my_strlen(acc) + 2; i++, j++) {
        chara = display_accuracy_chara_selector(acc, i, &j);
        sf_draw_sprite(game, SPR->number[chara],
        sf_vector_init(VMODE->width - XOFF - 32 - 44 * i, YOFF - 84));
    }
    free(acc);
    return 0;
}

int display_combo(game_t *game)
{
    char *combo = my_int_to_char(PLAYER->combo);
    int i = 0;
    for (i = 0; i < my_strlen(combo); i++) {
        sf_draw_sprite(game, SPR->number[DEC(combo[i])],
        sf_vector_init(XOFF + i * 46, YOFF + 660));
    }
    sf_draw_sprite(game, SPR->number[11],
    sf_vector_init(XOFF + i * 46, YOFF + 660));
    free(combo);
    return 0;
}
