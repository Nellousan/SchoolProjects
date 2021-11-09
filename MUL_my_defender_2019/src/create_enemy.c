/*
** EPITECH PROJECT, 2020
** create enemy
** File description:
** Obiwan Kenobi
*/

#include "my_graph.h"

enemy_t *create_enemy(int hp, int speed, sfSprite *sprite, sfVector2f coord)
{
    enemy_t *result = malloc(sizeof(enemy_t));

    if (result == NULL)
        return (NULL);
    result->hp = hp;
    result->speed = speed;
    result->status = 1;
    result->coord = coord;
    result->sprite = sfSprite_copy(sprite);
    if (result->sprite == NULL)
        return (NULL);
    sfSprite_setPosition(sprite, result->coord);
    return (result);
}

enemy_t **create_enemy_tab(void)
{
    enemy_t **result = malloc(sizeof(enemy_t) * 11);
    sfIntRect rect = {0, 0, 40, 40};
    sfTexture *texture = sfTexture_createFromFile("ball.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f coord = {0, 0};

    if (result == NULL || texture == NULL || sprite == NULL)
        return (NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, rect);
    for (int i = 0; i < 10; i++) {
        result[i] = create_enemy(1, 1, sprite, coord);
        coord.y +=10;
    }
    result[10] = NULL;
    return (result);
}
