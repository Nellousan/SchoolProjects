/*
** EPITECH PROJECT, 2020
** ls_dispay
** File description:
** 
*/

#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include "my.h"
#include "my_ls.h"

int my_ls_line_total(dir_t **dir)
{
    int blocks = 0;
    for (int i = 0; dir[i] != NULL; i++)
        blocks += (dir[i]->dir_r->d_name[0] != '.') ?
        dir[i]->stats.st_blocks : 0;
    my_printf("total %d\n", blocks / 2);
    return 0;
}

int ls_display_dir_element(my_ls_t *ls_param, dir_t *dir)
{
    if (LINE && dir->dir_r->d_name[0] != '.') {
        my_ls_line_type(dir->dir_r->d_type);
        my_ls_line_perms(dir->stats.st_mode);
        my_printf("%d ", dir->stats.st_nlink);
        my_ls_line_user_group(dir->stats.st_uid, dir->stats.st_gid, dir->stats);
        my_printf("%s\n", dir->dir_r->d_name);
    } else if (dir->dir_r->d_name[0] != '.')
        my_printf("%s\n", dir->dir_r->d_name);
    return 0;
}

int ls_display(my_ls_t *ls_param, dir_t **dir, char *dirpath)
{
    int dir_len;
    for (dir_len = 0; dir[dir_len + 1] != NULL; dir_len++);
    if (REC)
        my_printf("%s:\n", dirpath);
    if (LINE)
        my_ls_line_total(dir);
    if (REV) {
        for (int i = dir_len; i >= 0; i--)
            ls_display_dir_element(ls_param, dir[i]);
    } else {
        for (int i = 0; dir[i] != NULL; i++)
            ls_display_dir_element(ls_param, dir[i]);
    }
    return 0;
}
