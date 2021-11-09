/*
** EPITECH PROJECT, 2020
** info
** File description:
** lemin
*/

#include "../include/my.h"
#include "../include/lemin.h"

bool strcomp_links(char *tunnel, char *name)
{
    char *str = malloc(sizeof(char) * my_strlen(tunnel));
    size_t j = 0;
    size_t info = 0;

    for (size_t i = 0; tunnel[i]; i++) {
        if (info == 1) {
            str[j] = tunnel[i];
            j++;
        }
        if (tunnel[i] == '-') {
            info = 1;
        }
    }
    str[j] = '\0';
    if (my_strcomp(name, str) == true) {
        free(str);
        return true;
    }
    free(str);
    return false;
}

bool find_links(lemin_t *lemin, char *name, size_t i)
{
    if (my_strcomp(lemin->anthill[i], name) == true) {
        return true;
    }
    if (strcomp_links(lemin->anthill[i], name) == true) {
        return true;
    }
    return false;
}

size_t nb_links(lemin_t *lemin, char *name)
{
    size_t nb_links = 0;

    for (size_t i = 0; lemin->anthill[i]; i++) {
        if (verif_tunnel(lemin->anthill[i]) == true &&
        find_links(lemin, name, i) == true) {
            nb_links += 1;
        }
    }
    return nb_links;
}