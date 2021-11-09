/*
** EPITECH PROJECT, 2019
** chara header
** File description:
** 
*/

typedef struct chara_data
{
    sfVector2f grid_pos;
    sfVector2f position;
    sfImage *chara_i;
    sfSprite *chara_s;
    sfTexture *charaTex;
    char *map_sprite;
    char *name;
    int anim_frame;
    int pause_frame;
    int status;
} chara_data_t;

typedef struct choose_anim
{
    int id;
    int (*fptr)(sfRenderWindow, long, chara_data_t);
} choose_anim_t;

chara_data_t *lucina_init();
chara_data_t *chrom_init();
chara_data_t *olivia_init();
chara_data_t *anna_init();
