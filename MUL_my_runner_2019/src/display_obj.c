/*
** EPITECH PROJECT, 2020
** display obj
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

int display_obj_setcolor(game_t *game, obj_t *obj)
{
    if (MSEC(TIME) - MSEC(obj->dmg_time) <= 150)
        sfSprite_setColor(SPR->entity[obj->id][obj->e_status][obj->frame],
        DMG_COLOR);
    else
        sfSprite_setColor(SPR->entity[obj->id][obj->e_status][obj->frame],
        RESET_COLOR);
    return 0;
}

int display_obj_offset_selector(game_t *game, obj_t *obj)
{
    if (obj->facing == RIGHT) {
        sfSprite_setScale(SPR->entity[obj->id][obj->e_status][obj->frame],
        vec2f(-1, 1));
        return E_LIST[obj->id]->sprite_rect.width;
    }
    sfSprite_setScale(SPR->entity[obj->id][obj->e_status][obj->frame],
    vec2f(1, 1));
    return 0;
}

int display_obj(game_t *game)
{
    int xoff = 0;
    for (int i = 0; i < 32; i++) {
        if (OBJ[i]->obj_status == 1) {
            xoff = display_obj_offset_selector(game, OBJ[i]);
            display_obj_setcolor(game, OBJ[i]);
            draw_sprite(game,
            SPR->entity[OBJ[i]->id][OBJ[i]->e_status][OBJ[i]->frame],
            vec2f((VMODE.width / 2) + (OBJ[i]->pos.x - P_POS.x) -
            P_SWIDTH / 2 + xoff
            , OBJ[i]->pos.y));
        }
    }
    return 0;
}
