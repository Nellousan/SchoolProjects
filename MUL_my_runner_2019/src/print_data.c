/*
** EPITECH PROJECT, 2019
** data printing functions (debug purposes)
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

void print_entity_list(game_t *game)
{
    my_printf("\n***** Entity List *****\n\n");
    for (int i = 0; E_LIST[i] != NULL; i++) {
        my_printf("id: %d\nName: %s\n", E_LIST[i]->id, E_LIST[i]->name);
        my_printf("HP: %d\nDamage: %d\n", E_LIST[i]->hp, E_LIST[i]->damage);
        my_printf("Type: %d\n", E_LIST[i]->type);
        my_printf("Behaviour: %d\n", E_LIST[i]->behaviour);
        my_printf("Spritesheet: %s\n", E_LIST[i]->spritesheet);
        my_printf("Hurtbox: l: %d t: %d w: %d h: %d\n",
        E_LIST[i]->hurtbox.left, E_LIST[i]->hurtbox.top,
        E_LIST[i]->hurtbox.width, E_LIST[i]->hurtbox.height);
        my_printf("Hitbox: l: %d t: %d w: %d h: %d\n",
        E_LIST[i]->hitbox.left, E_LIST[i]->hitbox.top,
        E_LIST[i]->hitbox.width, E_LIST[i]->hitbox.height);
        my_printf("Sprite rect: l: %d t: %d w: %d h: %d\n",
        E_LIST[i]->sprite_rect.left, E_LIST[i]->sprite_rect.top,
        E_LIST[i]->sprite_rect.width, E_LIST[i]->sprite_rect.height);
        my_putchar('\n');
    }
    return;
}

void print_player(game_t *game)
{
    my_printf("\n***** Player Data *****\n\n");
    my_printf("Name: %s\nSpritesheet: %s\n", PLAYER->name, PLAYER->spritesheet);
    my_printf("HP: %d\n", PLAYER->max_hp);
    my_printf("Jump height: %d\n", PLAYER->jump_h);
    my_printf("Run Speed: %d\n", PLAYER->run_spd);
    my_printf("Hurtbox: l: %d t: %d w: %d h: %d\n",
    PLAYER->hurtbox.left, PLAYER->hurtbox.top,
    PLAYER->hurtbox.width, PLAYER->hurtbox.height);
    my_printf("Sprite rect: l: %d t: %d w: %d h: %d\n",
    PLAYER->sprite_rect.left, PLAYER->sprite_rect.top,
    PLAYER->sprite_rect.width, PLAYER->sprite_rect.height);
    return;
}

void print_player_atk(game_t *game)
{
    my_printf("\n***** PLayer Attack data *****\n\n");
    for (int i = 0; P_ATK[i] != NULL; i++) {
        my_printf("id: %d\nName %s\n", P_ATK[i]->id, P_ATK[i]->name);
        my_printf("Spritesheet: %s\n", P_ATK[i]->spritesheet);
        my_printf("Type: %d\nDamage: %d\n", P_ATK[i]->type, P_ATK[i]->damage);
        my_printf("Ling. Time: %d\n", P_ATK[i]->lingering_time);
        my_printf("Cooldown: %d\n", P_ATK[i]->cooldown);
        my_printf("Hitbox: l: %d t: %d w: %d h: %d\n",
        P_ATK[i]->hitbox.left, P_ATK[i]->hitbox.top,
        P_ATK[i]->hitbox.width, P_ATK[i]->hitbox.height);
        my_printf("Sprite rect: l: %d t: %d w: %d h: %d\n",
        P_ATK[i]->sprite_rect.left, P_ATK[i]->sprite_rect.top,
        P_ATK[i]->sprite_rect.width, P_ATK[i]->sprite_rect.height);
    }
    return;
}

void print_map_data(game_t *game)
{
    my_printf("\n***** Map Data *****\n\n");
    my_printf("Parallax: %d\n", MAP->parallax);
    for (int i = 0; i < MAP->parallax; i++)
        my_printf("Background: %s\n", MAP->spritesheet[i]);
    return;
}
