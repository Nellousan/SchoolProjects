/*
** EPITECH PROJECT, 2020
** structs
** File description:
** e
*/

#ifndef DEF_STRUCTS
#define DEF_STRUCTS

#include <SFML/Graphics.h>
#include <SFML/System.h>

typedef struct game game_t;

typedef struct map_node {
    sfVector2u pos;
    int type;
}mapn_t;

typedef struct map {
    char *sprsh;
    sfVector2u size;
    int nodesize;
    mapn_t **mapn;
    int **wave;
}map_t;

typedef struct tower_s {
    int id;
    char *sprsh;
    int range;
    int damage;
    int price;
    int evolve_id;
}tower_t;

typedef struct mob_d {
    int id;
    char *sprsh;
    int type;
    int hp;
    int damage;
}mob_d_t;

typedef struct animd {
    int framecount;
    int framespeed;
}animd_t;

typedef struct obj_tower {
    int obj_status;
    int status;
    int range;
    int damage;
    int id;
    int focus;
    int frame;
    sfVector2f pos;
    sfTime last_attack;
    sfTime frame_ch;
}o_tower_t;

typedef struct mob {
    int obj_status;
    int id;
    int type;
    int hp;
    int max_hp;
    int movespeed;
    int frame;
    int loot;
    int damage;
    int move;
    sfVector2f pos;
    sfTime frame_ch;
}o_mob_t;

typedef struct sprites {
    sfSprite ***mob;
    sfSprite ***towers;
    sfSprite *map;
}spr_t;

typedef struct obj {
    o_mob_t mob[32];
    o_tower_t tower[32];
}obj_t;

typedef struct player {
    int hp;
    int gold;
}player_t;

typedef struct button {
    sfIntRect hitbox;
    void (*fptr)(game_t *game);
}button_t;

typedef struct game {
    button_t *button;
    obj_t *obj;
    map_t *map;
    player_t *player;
    tower_t **tower_data;
    mob_d_t **mob_data;
    spr_t *spr;
    sfRenderWindow *window;
    sfVideoMode vmode;
    sfClock *clock;
}game_t;

#endif
