/*
** EPITECH PROJECT, 2020
** map_display
** File description:
** a
*/

#include "my.h"
#include "navy.h"

static int print_map_node(UNUSED game_t *game, mapn_t *map)
{
    if (map->hit == 1) {
        my_printf("x ");
        return 0;
    } if (map->hit == 2) {
        my_printf("o ");
        return 0;
    } if (map->ship != 0) {
        my_printf("%d ", map->ship);
        return 0;
    }
    my_printf(". ");
    return 0;
}

static int display_map(game_t *game, mapn_t **map)
{
    if (map == MAP)
        my_printf("my positions:\n");
    else
        my_printf("enemy's positions:\n");
    my_printf(" |A B C D E F G H\n-+---------------\n");
    for (int i = 0; i < 8; i++) {
        my_printf("%d|", i + 1);
        for (int j = 0; j < 8; j++) {
            print_map_node(game, map[i * 8 + j]);
        }
        my_printf("\n");
    }
    my_printf("\n");
    return 0;
}

int display_board(game_t *game)
{
    display_map(game, MAP);
    display_map(game, TMAP);
    return 0;
}
