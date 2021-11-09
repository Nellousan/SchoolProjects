/*
** EPITECH PROJECT, 2019
** char.c
** File description:
** character related func
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "chara.h"
#include "map.h"

chara_data_t *lucina_init()
{
    chara_data_t *lucina = malloc(sizeof(chara_data_t));
    lucina->map_sprite = my_strdup("sprites/lucina/lucina_map.png");
    lucina->name = my_strdup("Lucina");
    lucina->anim_frame = 0;
    lucina->pause_frame = rand() % 120;
    lucina->status = 0;
    lucina->position.x = 13 * 64;
    lucina->position.y = 9 * 64;
    lucina->grid_pos.x = 13;
    lucina->grid_pos.y = 9;
    return lucina;
}

chara_data_t *chrom_init()
{
    chara_data_t *chrom = malloc(sizeof(chara_data_t));
    chrom->map_sprite = my_strdup("sprites/chrom/chrom_map.png");
    chrom->name = my_strdup("Chrom");
    chrom->anim_frame = 0;
    chrom->pause_frame = rand() % 120;
    chrom->status = 0;
    chrom->position.x = 15 * 64;
    chrom->position.y = 10 * 64;
    chrom->grid_pos.x = 15;
    chrom->grid_pos.y = 10;
    return chrom;
}

chara_data_t *olivia_init()
{
    chara_data_t *olivia = malloc(sizeof(chara_data_t));
    olivia->map_sprite = my_strdup("sprites/olivia/olivia_map.png");
    olivia->name = my_strdup("Olivia");
    olivia->anim_frame = 0;
    olivia->pause_frame = rand() % 120;
    olivia->status = 0;
    olivia->position.x = 13 * 64;
    olivia->position.y = 5 * 64;
    olivia->grid_pos.x = 13;
    olivia->grid_pos.y = 9;
    return olivia;
}

chara_data_t *anna_init()
{
    chara_data_t *anna = malloc(sizeof(chara_data_t));
    anna->map_sprite = my_strdup("sprites/anna/anna_map.png");
    anna->name = my_strdup("Anna");
    anna->anim_frame = 0;
    anna->pause_frame = rand() % 120;
    anna->status = 0;
    anna->position.x = 17 * 64;
    anna->position.y = 7 * 64;
    anna->grid_pos.x = 17;
    anna->grid_pos.y = 8;
    return anna;
}
