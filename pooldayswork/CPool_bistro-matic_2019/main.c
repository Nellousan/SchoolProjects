/*
** EPITECH PROJECT, 2019
** test bistro changement de base
** File description:
**
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "bistro.h"
#define EXIT_INVALID_ARG "Invalid arguments\n"

int main(int argc, char **argv)
{
    char expr[512];
    read(0, expr, char_to_int(argv[3]));
    expr[char_to_int(argv[3])] = '\0';
    if (syntax_check(argc, argv, expr) == 84) {
        write(2, SYNTAX_ERROR_MSG, my_strlen(SYNTAX_ERROR_MSG));
        return 84;
    }
    char *res = disp_result(argv, expr);
    free(res);
    return 0;
}
