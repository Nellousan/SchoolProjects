/*
** EPITECH PROJECT, 2020
** boats load.c
** File description:
** aaaa
*/

#include <stddef.h>
#include "my.h"
#include "navy.h"
#include "a_malloc.h"

static int vect_check(vect_t v1, vect_t v2)
{
    vect_t res = VECT(v1.x - v2.x, v1.y - v2.y);
    int sum = ABS(res.x) + ABS(res.y) + 1;
    if (res.x != 0 && res.y != 0)
        return -1;
    else if (sum < 2 || sum > 5)
        return -1;
    return sum;
}

static int boats_set2(int sum, vect_t v1, vect_t v2, boats_t *boats)
{
    switch (sum) {
    case 4:
        if (boats->btlship_c)
            return 0;
        boats->btlship_c = set_battleship(v1, v2, boats);
        break;
    case 5:
        if (boats->cruiser_c)
            return 0;
        boats->cruiser_c = set_cruiser(v1, v2, boats);
        break;
    }
    return 1;
}

static int boats_set1(int sum, vect_t v1, vect_t v2, boats_t *boats)
{
    switch (sum) {
    case 2:
        if (boats->destr_c)
            return 0;
        boats->destr_c = set_destr(v1, v2, boats);
        break;
    case 3:
        if (boats->sub_c)
            return 0;
        boats->sub_c = set_sub(v1, v2, boats);
        break;
    }
    return 1;
}

static int boats_load_file(char *str, boats_t *boats)
{
    vect_t vect1 = extract_vect(copy_until(&str, ':'));
    vect_t vect2 = extract_vect(copy_until(&str, '\n'));
    int sum = vect_check(vect1, vect2);
    if (sum == -1)
        return 0;
    boats_set1(sum, vect1, vect2, boats);
    boats_set2(sum, vect1, vect2, boats);
    return 1;
}

boats_t *boats_load(char *filepath)
{
    boats_t *boats = a_malloc(sizeof(boats_t) | A_LIST(1));
    char *file = file_load(filepath);
    if (file == NULL)
        return NULL;
    boats->destr_c = 0;
    boats->sub_c = 0;
    boats->btlship_c = 0;
    boats->cruiser_c = 0;
    for (int i = 0; i < 4; i++) {
        file += 2;
        boats_load_file(copy_until(&file, '\n'), boats);
    }
    if (boats->destr_c == 0 || boats->sub_c == 0 || boats->btlship_c == 0 ||
    boats->cruiser_c == 0)
        return NULL;
    return boats;
}
