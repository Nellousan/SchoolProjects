/*
** EPITECH PROJECT, 2020
** standard ls command
** File description:
** 
*/

#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include "my.h"
#include "my_ls.h"
#include "a_malloc.h"

int my_ls_count_unit(char *dirpath)
{
    DIR *dir = opendir(dirpath);
    struct dirent *dir_r;
    int i = 1;
    dir_r = readdir(dir);
    while (dir_r != NULL) {
        i++;
        dir_r = readdir(dir);
    }
    closedir(dir);
    return i - 1;
}

dir_t **my_ls_dir_buffering(char *dirpath)
{
    int i = 0;
    char *filepath;
    int ls_unit = my_ls_count_unit(dirpath);
    DIR *dir = opendir(dirpath);
    dir_t **dir_data = a_malloc(sizeof(struct dir_t *) * (ls_unit + 1));
    for (i = 0; i < ls_unit; i++) {
        dir_data[i] = a_malloc(sizeof(dir_t));
        dir_data[i]->dir_r = readdir(dir);
        filepath = cat_dirpath_file(dirpath, dir_data[i]->dir_r->d_name);
        stat(filepath, &dir_data[i]->stats);
    }
    dir_data[i] = NULL;
    return dir_data;
}

int my_ls_rec(my_ls_t *ls_param, dir_t **dir, char *dirpath)
{
    for (int i = 0; dir[i] != NULL; i++)
        if (dir[i]->dir_r->d_type == DT_DIR && dir[i]->dir_r->d_name[0] != '.') {
            my_printf("\n");
            my_ls(ls_param, cat_dirpath_file(dirpath, dir[i]->dir_r->d_name));
        }
    return 0;
}

int my_ls(my_ls_t *ls_param, char *dirpath)
{
    dir_t **dir_data = my_ls_dir_buffering(dirpath);
    if (TIME)
        ls_sort_time(dir_data);
    ls_display(ls_param, dir_data, dirpath);
    if (REC)
        my_ls_rec(ls_param, dir_data, dirpath);
    return 0;
}
