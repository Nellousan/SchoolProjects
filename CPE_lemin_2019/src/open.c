/*
** EPITECH PROJECT, 2020
** open
** File description:
** lemin
*/

#include "../include/my.h"
#include "../include/lemin.h"
#include "../include/get_next_line.h"

char *cp_room(char *str)
{
    char *dest = malloc(sizeof(char) * (my_strlen(str) + 2));
    size_t i = 0;

    for (i = 0; str[i]; i++) {
        if (str[i] == '#') {
            i--;
            break;
        }
        dest[i] = str[i];
    }
    dest[i] = '\0';
    return dest;
}

void read_anthill(lemin_t *lemin)
{
    char *s = get_next_line(STDIN_FILENO);
    lemin->anthill = malloc(sizeof(char *) * 2048);
    size_t i = 0;

    while (s != NULL) {
        lemin->anthill[i] = my_strcp(s);
        i++;
        s = get_next_line(STDIN_FILENO);
    }
    lemin->anthill[i] = NULL;
}