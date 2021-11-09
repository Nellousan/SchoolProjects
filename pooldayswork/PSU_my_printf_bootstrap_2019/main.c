/*
** EPITECH PROJECT, 2019
** test main
** File description:
** 
*/

#include "my.h"

int sum_stdarg(int i, int nb, ...);
int disp_stdarg(char *s, ...);

int main()
{
    my_putstr("sum_stdarg(0, 4, 5, 7, 22, -2):\n");
    my_putnbr(sum_stdarg(0, 4, 5, 7, 22, -2));
    my_putstr("\n\n");
    my_putstr("sum_stdarg(1, 3, \"hello\", \"epitech\", \"world\")\n");
    my_putnbr(sum_stdarg(1, 3, "hello", "epitech", "world"));
    my_putstr("\n\n");
    my_putstr("disp_stdarg(\"iiscss\", 88, 27, \"hello\", 'a', \"bbbbbb\", \"boi\"):\n");
    disp_stdarg("iiscss", 88, 27, "hello", 'a', "bbbbbb", "boi");
    return 0;
}
