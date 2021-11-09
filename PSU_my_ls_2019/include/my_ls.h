/*
** EPITECH PROJECT, 2020
** my_ls header
** File description:
** 
*/

#ifndef MY_LS_H
#define MY_LS_H

#include <dirent.h>
#include <sys/stat.h>

/************* DEFINES ****************/

#define REC ls_param->rec
#define REV ls_param->rev
#define DIRE ls_param->dir
#define TIME ls_param->time
#define LINE ls_param->line
#define DIRPATH ls_param->dirpath

/************* STRUCTS ****************/

typedef struct dir_data {
    struct dirent *dir_r;
    struct stat stats;
}dir_t;

typedef struct my_ls {
    char *dirpath;
    int line;
    int rec;
    int rev;
    int dir;
    int time;
}my_ls_t;

/*************** LOAD *****************/

int my_ls_load(my_ls_t *ls_param, int argc, char **argv);

/**************** LS ******************/

int my_ls_redirect(my_ls_t *ls_param);
int my_ls(my_ls_t *ls_param, char *dirpath);
int ls_display(my_ls_t *ls_param, dir_t **dir, char *dirpath);
int ls_sort_time(dir_t **dir);
int my_ls_line_type(unsigned char d_type);
int my_ls_line_perms(mode_t mode);
int my_ls_line_user_group(uid_t uid, gid_t gid, struct stat stats);

/*************** MISC *****************/

int char_in_string(char *str, char c);
char *ls_strcat(char *str1, char *str2);
char *cat_dirpath_file(char *dirpath, char *file);

/**************************************/



/**************************************/

#endif
