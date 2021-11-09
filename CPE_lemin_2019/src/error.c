/*
** EPITECH PROJECT, 2020
** error
** File description:
** lemin
*/

#include "../include/my.h"
#include "../include/lemin.h"
#include "../include/get_next_line.h"

char *my_strcp(char *str)
{
    char *dest = malloc(sizeof(char) * (my_strlen(str) + 2));
    size_t i = 0;

    for (i = 0; str[i]; i++) {
        dest[i] = str[i];
    }
    dest[i] = '\0';
    return dest;
}

bool my_strcomp(char *str, char *s)
{
    for (int i = 0; s[i]; i++) {
        if (str[i] != s[i])
            return false;
    }
    return true;
}

char *find_name(char *str)
{
    char *name = malloc(sizeof(char) * my_strlen(str));

    for (size_t i = 0; str[i]; i++) {
        if (str[i] == ' ') {
            name[i] = '\0';
            break;
        }
        name[i] = str[i];
    }
    return name;
}

bool error_nb_tunnel(lemin_t *lemin)
{
    char * name = NULL;
    size_t link = 0;

    for (size_t i = 0; lemin->anthill[i]; i++) {
        if (verif_room(lemin->anthill[i]) == true) {
            name = find_name(lemin->anthill[i]);
            link = nb_links(lemin, name);
            if (link == 0)
                return true;
        }
    }
    return false;
}

bool error_anthill(lemin_t *lemin)
{
    size_t start = 0;
    size_t end = 0;
    size_t tunnel = 0;

    for (size_t i = 0; lemin->anthill[i]; i++) {
        if (my_strcomp(lemin->anthill[i], "##end") == true &&
        lemin->anthill[i + 1] != NULL &&
        verif_room(lemin->anthill[i + 1]) == true)
            end += 1;
        if (my_strcomp(lemin->anthill[i], "##start") == true &&
        lemin->anthill[i + 1] != NULL &&
        verif_room(lemin->anthill[i + 1]) == true)
            start += 1;
        if (verif_tunnel(lemin->anthill[i]) == true)
            tunnel += 1;
    }
    if (end == 0 || start == 0 || verif_nb_ant(lemin) == true ||
    tunnel == 0 || error_nb_tunnel(lemin) == true)
        return true;
    return false;
}