/*
** EPITECH PROJECT, 2020
** CPE_duo_stumper_1_2019
** File description:
** fractals
*/

#include "fractals_s.h"
#include <stdlib.h>

void fill_2d_tab(vect2u_t p, char **dest, char **src)
{
    int x;

    for (size_t i = 0; src[i] != NULL; i++) {
        x = p.x;
        for (size_t j = 0; src[i][j] != '\0'; j++) {
            dest[p.y][x] = src[i][j];
            x++;
        }
        p.y++;
    }
}
