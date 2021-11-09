/*
** EPITECH PROJECT, 2019
** load player data
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

void fuck_la_norme_v2(char **file, p_atk_t *p_atk)
{
    p_atk->anim_data = extract_anim_node(copy_until(file, ';'));
    p_atk->key = char_to_int(copy_until(file, '\n'));
    p_atk->tex = sfTexture_createFromFile(run_strcat(
    SPR_DIR, p_atk->spritesheet), NULL);
    p_atk->spr = sprite_array_load(p_atk->tex, p_atk->sprite_rect,
    p_atk->anim_data->framecount, 0);
    p_atk->frame = 0;
}

p_atk_t **player_attack_load(void)
{
    char *file = file_load("data/player_attack_data");
    char *file_c = file;
    int i = 0;
    p_atk_t **p_atk = malloc(sizeof(p_atk_t *) * (get_ret_count(file) + 1));
    for (; i < get_ret_count(file); i++) {
        p_atk[i] = malloc(sizeof(p_atk_t));
        p_atk[i]->id = char_to_int(copy_until(&file, ';'));
        p_atk[i]->name = copy_until(&file, ';');
        p_atk[i]->spritesheet = copy_until(&file, ';');
        p_atk[i]->type = char_to_int(copy_until(&file, ';'));
        p_atk[i]->damage = char_to_int(copy_until(&file, ';'));
        p_atk[i]->lingering_time = char_to_int(copy_until(&file, ';'));
        p_atk[i]->cooldown = char_to_int(copy_until(&file, ';'));
        p_atk[i]->hitbox = extract_rect(copy_until(&file, ';'));
        p_atk[i]->sprite_rect = extract_rect(copy_until(&file, ';'));
        fuck_la_norme_v2(&file, p_atk[i]);
    }
    p_atk[i] = NULL;
    free(file_c);
    return p_atk;
}

animn_t *extract_anim_node(char *str)
{
    char *str_c = str;
    animn_t *node = malloc(sizeof(animn_t));
    node->framecount = char_to_int(copy_until(&str, '.'));
    node->loop = char_to_int(copy_until(&str, '.'));
    node->loop_frame = char_to_int(copy_until(&str, '.'));
    node->frame_spd = char_to_int(copy_until(&str, '\0'));
    free(str_c);
    return node;
}

animn_t **anim_data_load(char **file)
{
    animn_t **animd = malloc(sizeof(animn_t *) * 7);
    for (int i = 0; i < 7; i++) {
        animd[i] = extract_anim_node(copy_until(file, ';'));
    }
    return animd;
}

player_t *player_load(void)
{
    char *file = file_load("data/player_data");
    char *file_c = file;
    player_t *player = malloc(sizeof(player_t));
    player->name = copy_until(&file, ';');
    player->spritesheet = copy_until(&file, ';');
    player->hitsound = sfMusic_createFromFile("song/hitsound.ogg");
    player->max_hp = char_to_int(copy_until(&file, ';'));
    player->jump_h = char_to_int(copy_until(&file, ';'));
    player->jump_spd = char_to_int(copy_until(&file, ';'));
    player->run_spd = char_to_int(copy_until(&file, ';'));
    player->hurtbox = extract_rect(copy_until(&file, ';'));
    player->sprite_rect = extract_rect(copy_until(&file, '\n'));
    player->anim_data = anim_data_load(&file);
    player->player_atk = player_attack_load();
    player->anim_s = idle;
    player->frame = 0;
    free(file_c);
    return player;
}
