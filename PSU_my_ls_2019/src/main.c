/*
** EPITECH PROJECT, 2020
** ls main
** File description:
** 
*/

#include <stdlib.h>
#include "my.h"
#include "my_ls.h"

int main(int argc, char **argv)
{
    my_ls_t ls_param;
    my_ls_load(&ls_param, argc, argv);
    my_ls(&ls_param, ls_param.dirpath);
    return 0;
}
