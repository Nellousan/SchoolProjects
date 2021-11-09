/*
** EPITECH PROJECT, 2019
** rush1
** File description:
** gotta go fast
*/

#include <unistd.h>

void my_putchar(char c);

int error_management(int x, int y)
{
    if (x <= 0 || y <= 0) {
        write(2, "Invalid size\n", 13);
        return (84);
    } else
        return (0);
}

void put_first_and_last_line(int corner1, char corner2, char horizontal, int x)
{
    if (x == 1) {
        my_putchar('o');
        my_putchar('\n');
        return;
    }
    for (int i = 0; i < x; i++) {
        if (x > 1 && i == 0)
            my_putchar(corner1);
        else if (x > 1 && i == x - 1)
            my_putchar(corner2);
        else
            my_putchar(horizontal);
    }
    my_putchar('\n');
}

void put_intermediary_line(char vertical, int x)
{
    for (int i = 0; i < x; i++) {
        if (i == 0 || i == x - 1)
            my_putchar(vertical);
        else
            my_putchar(' ');
    }
    my_putchar('\n');
}

void my_put_special(char corner1, char horizontal, char corner2, int x)
{
    for (int i = 0; i < x; i++) {
        if (i == 0)
            my_putchar(corner1);
        else if (i == x - 1)
            my_putchar(corner2);
        else
            my_putchar(horizontal);
    }
    my_putchar('\n');
}

void rush(int x, int y)
{
    char *tab = "oooo\0";
    char horizontal = '-';
    char vertical = '|';

    if (error_management(x, y) == 84)
        return;
    for (int i = 0; i < y; i++) {
        if (i == 0 && y != 1)
            put_first_and_last_line(tab[0], tab[1], horizontal, x);
        else if (i == y - 1 && y!= 1)
            put_first_and_last_line(tab[2], tab[3], horizontal, x);
        if (i != 0 && i != y - 1)
            put_intermediary_line(vertical, x);
        else if (y == 1)
            my_put_special('o', horizontal, 'o', x);
    }
}
