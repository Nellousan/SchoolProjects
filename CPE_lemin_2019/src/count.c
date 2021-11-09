/*
** EPITECH PROJECT, 2020
** count
** File description:
** c
*/

#include "lemin.h"
#include "my.h"

bool is_room(char *str)
{
    if (str[0] == '#')
        return false;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ' ')
            return true;
    return false;
}

bool is_link(char *str)
{
    if (str[0] == '#')
        return false;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '-')
            return true;
    return false;
}

void count(lemin_t *lemin, int *rooms, int *links)
{
    int croom = 0;
    int clink = 0;
    for (int i = 0; ANTHILL[i] != NULL; i++) {
        if (is_room(ANTHILL[i]))
            croom++;
        if (is_link(ANTHILL[i]))
            clink++;
    }
    (*rooms) = croom;
    (*links) = clink;
    return;
}

int count_node(lemin_t *lemin)
{
    int i = 0;
    for (i = 0; NODE[i] != NULL; i++);
    return i;
}
