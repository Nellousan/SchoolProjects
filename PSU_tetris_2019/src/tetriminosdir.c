/*
** EPITECH PROJECT, 2020
** tetriminos
** File description:
** dir
*/

#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <dirent.h>
#include "my.h"
#include "a_malloc.h"
#include "tetris.h"

static bool is_tetrimino(char *d_name)
{
    for (; d_name[0] != '.' && d_name[0] != '\0'; d_name++);
    if (!my_strcmp(d_name, ".tetrimino"))
        return true;
    return false;
}

static int count_tetrimino(void)
{
    DIR *dir = opendir("tetriminos");
    struct dirent *dir_r;
    int i = 0;
    dir_r = readdir(dir);
    i += (dir_r && is_tetrimino(dir_r->d_name)) ? 1 : 0;
    while (dir_r != NULL) {
        dir_r = readdir(dir);
        i += (dir_r && is_tetrimino(dir_r->d_name)) ? 1 : 0;
    }
    closedir(dir);
    return i;
}

char **list_tetrimino(void)
{
    DIR *dir = opendir("tetriminos");
    struct dirent *dir_r;
    char **res = a_malloc(sizeof(char *) * (count_tetrimino() + 1));
    int i = 0;
    dir_r = readdir(dir);
    if (dir_r && is_tetrimino(dir_r->d_name)) {
        res[i] = my_strdup(dir_r->d_name);
        i++;
    }
    while (dir_r != NULL) {
        dir_r = readdir(dir);
        if (dir_r && is_tetrimino(dir_r->d_name)) {
            res[i] = my_strdup(dir_r->d_name);
            i++;
        }
    }
    res[i] = NULL;
    return res;
}
