/*
** EPITECH PROJECT, 2019
** load util part 2
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

char *run_strcat(char *str1, char *str2)
{
    char *res = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 1));
    int i = 0;
    for (int j = 0; str1[j] != '\0'; i++, j++)
        res[i] = str1[j];
    for (int j = 0; str2[j] != '\0'; i++, j++)
        res[i] = str2[j];
    res[i] = '\0';
    return res;
}

sfSprite *sprite_create(sfTexture *tex, sfIntRect *rect)
{
    sfSprite *spr = sfSprite_create();
    sfSprite_setTexture(spr, tex, sfTrue);
    if (rect != NULL)
        sfSprite_setTextureRect(spr, *rect);
    return spr;
}

sfSprite *sprite_create_from_file(char *path)
{
    sfTexture *tex = sfTexture_createFromFile(run_strcat(SPR_DIR, path), NULL);
    sfSprite *spr = sprite_create(tex, NULL);
    return spr;
}

sfSprite **sprite_array_load(sfTexture *tex, sfIntRect rect, int amnt, int h)
{
    sfSprite **sprarr = malloc(sizeof(sfSprite*) * amnt);
    sfIntRect rect_c = rect;
    int top = rect.height * h;
    for (int i = 0; i < amnt; i++) {
        rect_c = rect(rect_c.width * i, top, rect_c.width, rect_c.height);
        sprarr[i] = sprite_create(tex, &rect_c);
    }
    return sprarr;
}

sfVector2f extract_vect(char *str)
{
    char *str_c = str;
    sfVector2f vect;
    vect.x = char_to_int(copy_until(&str, '.'));
    vect.y = char_to_int(copy_until(&str, '\0'));
    free(str_c);
    return vect;
}
