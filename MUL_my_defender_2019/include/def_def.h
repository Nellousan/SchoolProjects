/*
** EPITECH PROJECT, 2020
** defines
** File description:
** s
*/

#ifndef DEF_DEF
#define DEF_DEF

#define OBJ game->obj
#define MOB game->obj->mob
#define TOWER game->obj->tower
#define MAP game->map
#define MAPN game->map->mapn
#define PLAYER game->player
#define SPR game->spr
#define TOWERD game->tower_data
#define MOBD game->mob_data
#define WINDOW game->window
#define VMODE game->vmode
#define BUTTON game->button
#define CLOCK game->clock
#define TIME sfClock_getElapsedTime(CLOCK)
#define UNUSED __attribute__((unused))

#define WINNAME "Soopah Defender"

#define GETMS(x) ((x).microseconds / 1000)
#define SFVMODE(x, y, z) (sfVideoMode){(x), (y), (z)}
#define SFVEC2F(x, y) (sfVector2f){(x), (y)}
#define SFVEC2U(x, y) (sfVector2u){(x), (y)}
#define SFIRECT(l, t, w, h) (sfIntRect){(l), (t), (w), (h)}
#define DEC(x) ((x) - '0')

#endif
