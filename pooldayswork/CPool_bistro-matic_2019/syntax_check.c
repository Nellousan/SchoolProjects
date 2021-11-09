/*
** EPITECH PROJECT, 2019
** syntax error handling
** File description:
** syntax error handling
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "bistro.h"

void fill_bzero(char *str, int size)
{
    for (int i = 0; i < size; i++)
        str[i] = '\0';
    return;
}

int check_char_base(char c, char *base)
{
    for (int i = 0; base[i] != '\0'; i++)
        if (c == base[i])
            return 1;
    return 0;
}

int base_validity_check(char *nb_base, char *sym_base)
{
    char *nb_base_buf = malloc(sizeof(char) * my_strlen(nb_base) + 1);
    char *sym_base_buf = malloc(sizeof(char) * my_strlen(nb_base) + 1);

    fill_bzero(nb_base_buf, my_strlen(nb_base) + 1);
    fill_bzero(sym_base_buf, my_strlen(sym_base) + 1);
    if (my_strlen(sym_base) != 7)
        return 84;
    for (int i = 0; nb_base[i] != '\0'; i++)
        if (check_char_base(nb_base[i], nb_base_buf))
            return 84;
        else
            nb_base_buf[i] = nb_base[i];
    for (int i = 0; sym_base[i] != '\0'; i++)
        if (check_char_base(sym_base[i], sym_base_buf))
            return 84;
        else
            sym_base_buf[i] = sym_base[i];
    return 0;
}

int check_expr_base(char *expr, char **argv)
{
    for (int i = 0; i < char_to_int(argv[3]); i++)
        if (!check_char_base(expr[i], argv[1]) &&
            !check_char_base(expr[i], argv[2]))
            return 84;
    return 0;
}

int syntax_check(int argc, char **argv, char *expr)
{
    if (argc < 4)
        return 84;
    if (base_validity_check(argv[1], argv[2]) == 84 ||
        check_expr_base(expr, argv) == 84)
        return 84;
    return 0;
}
