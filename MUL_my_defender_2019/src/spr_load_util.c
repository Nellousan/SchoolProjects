/*
** EPITECH PROJECT, 2020
** spr 
** File description:
** laod
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my.h"
#include "defender.h"
#include "a_malloc.h"

sfSprite *sprite_create_from_file(char *str, sfIntRect *rect)
{
    sfTexture *tex = sfTexture_createFromFile(str, NULL);
    sfSprite *spr = sfSprite_create();
    sfSprite_setTexture(spr, tex, sfTrue);
    if (rect)
        sfSprite_setTextureRect(spr, *rect);
    return spr;
}

sfSprite *sprite_create(sfTexture *tex, sfIntRect *rect)
{
    sfSprite *spr = sfSprite_create();
    sfSprite_setTexture(spr, tex, sfFalse);
    if (rect)
        sfSprite_setTextureRect(spr, *rect);
    return spr;
}

sfSprite **load_sprite_array(char *str, sfIntRect r, int amnt)
{
    sfTexture *tex = sfTexture_createFromFile(str, NULL);
    sfSprite **spr = a_malloc(sizeof(sfSprite *) * (amnt + 1) | A_LIST(1));
    int i = 0;
    int w = r.width;
    for (i = 0; i < amnt; i++) {
        r = SFIRECT(r.left + (w * i), r.top, r.width, r.height);
        spr[i] = sprite_create(tex, &r);
    }
    spr[i] = NULL;
    return spr;
}
