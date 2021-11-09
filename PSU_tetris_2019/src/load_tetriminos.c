/*
** EPITECH PROJECT, 2020
** load
** File description:
** tetriminos
*/

#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "tetris.h"
#include "my.h"
#include "a_malloc.h"

static void tetri_clear_body(char **body)
{
    for (int i = 0; body[i] != NULL; i++) {
        for (int j = 0; body[i][j] != '\0'; j++) {
            body[i][j] = (body[i][j] == '\n') ? '\0' : body[i][j];
        }
    }
    return;
}

static tetri_t *tetri_unit_load(char *filep)
{
    char *file = file_load(mstrcat("tetriminos/", filep));
    tetri_t *tetri = a_malloc(sizeof(tetri_t) | A_LIST(1));
    int x = my_atoi(cpdelim(&file, ' '));
    int y = my_atoi(cpdelim(&file, ' '));
    int i = 0;
    tetri->size = VECT(x, y);
    tetri->color = my_atoi(cpdelim(&file, '\n'));
    tetri->body = a_malloc(sizeof(char *) * (tetri->size.y + 1) | A_LIST(1));
    for (i = 0; i < tetri->size.y; i++) {
        tetri->body[i] = my_astrdup(cpdelim(&file, '\n'), 1);
    }
    tetri->body[i] = NULL;
    tetri->name = my_astrdup(cpdelim(&filep, '.'), 1);
    tetri_clear_body(tetri->body);
    return tetri;
}

tetri_t **tetri_load(void)
{
    char **t_list = list_tetrimino();
    tetri_t **tetri;
    int i = 0;
    for (i = 0; t_list[i] != NULL; i++);
    tetri = a_malloc(sizeof(tetri_t *) * (i + 1) | A_LIST(1));
    for (i = 0; t_list[i] != NULL; i++) {
        tetri[i] = tetri_unit_load(t_list[i]);
    }
    tetri[i] = NULL;
    return tetri;
}
