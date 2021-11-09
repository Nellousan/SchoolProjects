/*
** EPITECH PROJECT, 2020
** verif
** File description:
** lemin
*/

#include "../include/my.h"
#include "../include/lemin.h"

bool verif_nb_ant(lemin_t *lemin)
{
    size_t i = 0;

    if (lemin->anthill[0][0] == '#')
        i = 1;
    for (size_t j = 0; lemin->anthill[i][j]; j++) {
        if (lemin->anthill[i][j] < '0' || lemin->anthill[i][j] > '9') {
            return true;
        }
    }
    return false;
}

bool verif_tunnel(char *str)
{
    size_t space = 0;
    size_t tunnel = 0;

    for (size_t i = 0; str[i]; i++) {
        if (str[i] == ' ') {
            space += 1;
        }
        if (str[i] == '-') {
            tunnel += 1;
        }
        if (str[i] == '#') {
            space -= 1;
        }
    }
    if (tunnel == 1 && space == 0) {
        return true;
    }
    return false;
}

bool verif_room_info(char *str, size_t i)
{
    for (size_t j = 0; str[i]; j++, i++) {
        if ((str[i] == ' ' && j > 0) || str[i] == '#')
            return true;
        if ((str[i] < '0' || str[i] > '9') && str[i] != ' ') {
            return false;
        }
    }
    return true;
}

bool verif_room(char *str)
{
    size_t space = 0;

    for (size_t i = 0; str[i]; i++) {
        if (str[i] == ' ' && verif_room_info(str, i) == true)
            space += 1;
        if (str[i] == ' ' && verif_room_info(str, i) == false) {
            return false;
        }
        if (str[i] == '#') {
            space -= 1;
            break;
        }
    }
    if (space == 2) {
        return true;
    }
    return false;
}