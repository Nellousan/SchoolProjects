/*
** EPITECH PROJECT, 2019
** entity_list loading function
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

animn_t **e_anim_data_load(char **file)
{
    animn_t **animd = malloc(sizeof(animn_t *) * 3);
    for (int i = 0; i < 3; i++) {
        animd[i] = extract_anim_node(copy_until(file, ';'));
    }
    return animd;
}

void fuck_la_norme(char **file, e_list_t *e_list)
{
    e_list->hitbox = extract_rect(copy_until(file, ';'));
    e_list->sprite_rect = extract_rect(copy_until(file, ';'));
    e_list->anim_data = e_anim_data_load(file);
    e_list->spritesheet = copy_until(file, '\n');
    return;
}

e_list_t **e_list_load(void)
{
    char *file = file_load("data/entity_data");
    char *file_c = file;
    int i = 0;
    e_list_t **e_list = malloc(sizeof(e_list_t *) * (get_ret_count(file) + 1));
    for (; i < get_ret_count(file_c); i++) {
        e_list[i] = malloc(sizeof(e_list_t));
        e_list[i]->id = char_to_int(copy_until(&file, ';'));
        e_list[i]->name = copy_until(&file, ';');
        e_list[i]->hp = char_to_int(copy_until(&file, ';'));
        e_list[i]->damage = char_to_int(copy_until(&file, ';'));
        e_list[i]->type = char_to_int(copy_until(&file, ';'));
        e_list[i]->behaviour = char_to_int(copy_until(&file, ';'));
        e_list[i]->run_spd = char_to_int(copy_until(&file, ';'));
        e_list[i]->hurtbox = extract_rect(copy_until(&file, ';'));
        fuck_la_norme(&file, e_list[i]);
    }
    e_list[i] = NULL;
    free(file_c);
    return e_list;
}
