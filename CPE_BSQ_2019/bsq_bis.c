/*
** EPITECH PROJECT, 2019
** bsq bis
** File description:
** 
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "bsq.h"

int *int_map_init(char *map)
{
    int len = my_strlen(map);
    int l_len = get_line_len(map) - 1;
    int *intmap = malloc(sizeof(int) * len + 1);
    int j = 0;
    int ret_cnt = 0;
    for (int i = 0; map[i] != '\0'; i++, j++) {
        if ((map[i] != '.' && map[i] != 'o' && map[i] != '\n') ||
            (map[i] == '\n' && (i + ret_cnt) % l_len != 0)) {
            return NULL;
        } if (map[i] == '\n') {
            j--;
            ret_cnt--;
        }
        intmap[j] = (map[i] == '.') ? 1 : intmap[j];
        intmap[j] = (map[i] == 'o') ? 0 : intmap[j];
    }
    intmap[j] = -1;
    return intmap;
}

int min(int nb1, int nb2, int nb3)
{
    if (nb1 <= nb2 && nb1 <= nb3)
        return nb1;
    else if (nb2 <= nb1 && nb2 <= nb3)
        return nb2;
    else
        return nb3;
    return 0;
}

int find_square(int *map, sq_vect_t *big_sq, char *charmap)
{
    int l_len = get_line_len(charmap) - 1;
    for (int i = l_len + 1; map[i] != -1; i++) {
        if (i % l_len == 0) {}
        else if (map[i] > 0) {
            map[i] = 1 + min(map[i - l_len], map[i - l_len - 1], map[i - 1]);
        }
        if (map[i] > big_sq->size) {
            big_sq->size = map[i];
            big_sq->x = i % l_len;
            big_sq->y = i / l_len;
        }
    }
    return 0;
}

int draw_square_in_map(char *map, sq_vect_t *sq)
{
    int len = get_line_len(map);
    for (int i = 0; i < sq->size; i++) {
        for (int j = 0; j < sq->size; j++) {
            map[NORM_DEF] = (map[NORM_DEF] == '.') ? 'x' : map[NORM_DEF];
        }
    }
    return 0;
}

int bsq(char *map, sq_vect_t *big_sq)
{
    int map_offset = move_map_ptr(&map);
    if (map_offset == -1)
        return 84;
    int *intmap = int_map_init(map);
    if (intmap == NULL)
        return 84;
    if (get_ret_count(map) - 1 == 1 || get_line_len(map) - 1 == 1)
        line_case(map);
    else {
        find_square(intmap, big_sq, map);
        draw_square_in_map(map, big_sq);
    }
    write(1, map, my_strlen(map));
    return 0;
}
