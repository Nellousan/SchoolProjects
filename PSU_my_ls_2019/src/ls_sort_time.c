/*
** EPITECH PROJECT, 2020
** sort time
** File description:
** 
*/

#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include "my.h"
#include "my_ls.h"

int ls_is_time_sorted(dir_t **dir)
{
    for (int i = 1; dir[i] != NULL; i++)
        if (dir[i - 1]->stats.st_mtime < dir[i]->stats.st_mtime)
            return 0;
    return 1;
}

int ls_sort_time_loop(dir_t **dir)
{
    dir_t *buf;
    for (int i = 1; dir[i] != NULL; i++)
        if (dir[i - 1]->stats.st_mtime < dir[i]->stats.st_mtime) {
            buf = dir[i];
            dir[i] = dir[i - 1];
            dir[i - 1] = buf;
        }
    return 0;
}

int ls_sort_time(dir_t **dir)
{
    while (!ls_is_time_sorted(dir))
        ls_sort_time_loop(dir);
    return 0;
}
