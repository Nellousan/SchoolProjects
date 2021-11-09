/*
** EPITECH PROJECT, 2020
** display
** File description:
** lemin
*/

#include "../include/my.h"
#include "../include/lemin.h"

bool check_tunnels(lemin_t *lemin, size_t i)
{
    size_t space = 0;
    size_t tunnels = 0;

    for (size_t j = 0; lemin->anthill[i][j]; j++) {
        if (lemin->anthill[i][j] == '-') {
            tunnels = 1;
        }
        if (lemin->anthill[i][j] == ' ') {
            space = 1;
        }
    }
    if (space == 0 && tunnels == 1) {
        return true;
    }
    return false;
}

void display_tunnels(lemin_t *lemin)
{
    for (size_t i = 0; lemin->anthill[i]; i++) {
        if (check_tunnels(lemin, i) == true) {
            my_putstr(lemin->anthill[i]);
            my_putchar('\n');
        }
    }
}

void display_room(lemin_t *lemin)
{
    char *room = NULL;

    for (size_t i = 1; check_tunnels(lemin, i) == false; i++) {
        if (lemin->anthill[i][0] == '#' && lemin->anthill[i][1] != '#') {
            continue;
        }
        if (lemin->anthill[i][0] == '#' && lemin->anthill[i][1] == '#') {
            my_putstr(lemin->anthill[i]);
            my_putchar('\n');
        }
        else {
            room = cp_room(lemin->anthill[i]);
            my_putstr(room);
            my_putchar('\n');
        }
    }
}

void display(lemin_t *lemin)
{
    my_putstr("#number_of_ants\n");
    my_putstr(lemin->anthill[0]);
    my_putstr("\n#rooms\n");
    display_room(lemin);
    my_putstr("#tunnels\n");
    display_tunnels(lemin);
    my_putstr("#moves\n");
}
