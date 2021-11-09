/*
** EPITECH PROJECT, 2019
** isoperand
** File description:
** operand
*/

#include "../../include/bistro.h"

int isop(char ch, char **argv)
{
    if (check_char_base(ch, argv[1]))
        return 1;
    if (ch == argv[2][2] ||ch == argv[2][3]
        ||ch == argv[2][4] ||ch == argv[2][5] ||ch == argv[2][6])
        return 2;
    return 0;
}
