/*
** EPITECH PROJECT, 2020
** dhao
** File description:
** dap
*/

#include "my.h"

void display_help(void)
{
    my_printf("USAGE:\n");
    my_printf("\t./palindrome -n number -p palindrome ");
    my_printf("[-b base] [-imin i] [-imax i]\n");
    my_printf("DESCRIPTION:\n\t-n n\tinteger to be transformed (>=0)\n");
    my_printf("\t-p pal\tpalindromic number to be obtained");
    my_printf(" (incompatible with the -noption) (>=0)\n");
    my_printf("\t\tif defined, all fitting values of n will be output\n");
    my_printf("\t-b base\tbase in which the procedure");
    my_printf(" will be executed (1<b<=10) [def: 10]\n");
    my_printf("\t-imin i\tminimum number of iterations,");
    my_printf(" included (>=0) [def: 0]\n");
    my_printf("\t-imax i\tmaximum number of iterations,");
    my_printf(" included (>=0) [def: 100]\n");
}
