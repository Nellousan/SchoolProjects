/*
** EPITECH PROJECT, 2020
** ls params load
** File description:
** 
*/

#include <stdlib.h>
#include "my.h"
#include "my_ls.h"

int my_ls_load_extract_param(my_ls_t *ls_param, char *str)
{
    for (int i = 1; str[i] != '\0'; i++) {
        switch (str[i]) {
        case 'l':
            LINE = 1;
            break;
        case 'R':
            REC = 1;
            break;
        case 'r':
            REV = 1;
            break;
        case 't':
            TIME = 1;
            break;
        case 'd':
            DIRE = 1;
            break;
        }
    }
    return 0;
}

int my_ls_load_param_init(my_ls_t *ls_param)
{
    LINE = 0;
    REC = 0;
    REV = 0;
    TIME = 0;
    DIRE = 0;
    return 0;
}

int my_ls_load(my_ls_t *ls_param, int argc, char **argv)
{
    int i = 0;
    my_ls_load_param_init(ls_param);
    for (i = 1; i < argc && argv[i][0] == '-'; i++)
        my_ls_load_extract_param(ls_param, argv[i]);
    if (i == argc)
        DIRPATH = my_strdup(".");
    else
        DIRPATH = my_strdup(argv[i]);
    return 0;
}
