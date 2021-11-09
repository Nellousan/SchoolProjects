/*
** EPITECH PROJECT, 2020
** road
** File description:
** lemin
*/

#include "../include/my.h"
#include "../include/lemin.h"

void display_pos(lemin_t *lemin, size_t i, size_t nb)
{
    char *pos = malloc(sizeof(char) * 2048);
    char *id = my_int_to_char(i);
    size_t j = 0;
    size_t x = 1;

    pos[0] = 'p';
    for (j = 0; id[j]; j++, x++)
        pos[x] = id[j];
    pos[x] = '-';
    x++;
    for (j = 0; NODE[nb]->name[j]; j++, x++)
        pos[x] = NODE[nb]->name[j];
    pos[x] = '\0';
    my_putstr(pos);
    my_putchar(' ');
    free(pos);
}

static int find_node_id(lemin_t *lemin, char *str)
{
    for (int i = 0; NODE[i] != NULL; i++) {
        if (!my_strcmp(NODE[i]->name, str))
            return NODE[i]->id;
    }
    return -1;
}

int change_room(lemin_t *lemin, size_t i, size_t j)
{
    if (lemin->ant_list[i]->pos_id == find_node_id(lemin,
    lemin->solution[0][j])
    && lemin->solution[0][j + 1] != NULL) {
        if (i > 0 && lemin->ant_list[i - 1]->pos_id ==
        find_node_id(lemin, lemin->solution[0][j + 1])) {
            return -1;
        }
        lemin->ant_list[i]->pos_id = find_node_id(lemin,
        lemin->solution[0][j + 1]);
        display_pos(lemin, lemin->ant_list[i]->id, lemin->ant_list[i]->pos_id);
        return 1;
    }
    if (lemin->ant_list[i]->pos_id == find_node_id(lemin, lemin->solution[0][j])
    && lemin->solution[0][j + 1] == NULL) {
        lemin->ant_list[i]->pos_id = -1;
    }
    return 0;
}

int find_road(lemin_t *lemin, size_t i)
{
    int status = 0;

    if (lemin->ant_list[i]->pos_id != -1) {
        for (size_t j = 0; lemin->solution[0][j]; j++) {
            status = change_room(lemin, i, j);
            if (status != 0)
                return status;
        }
    }
    return 0;
}

void road(lemin_t *lemin)
{
    while (lemin->ant_list[lemin->nb_ant - 1]->pos_id != -1) {
        for (size_t i = 0; i < lemin->nb_ant; i++) {
            if (find_road(lemin, i) == -1)
                break;
        }
        if (lemin->ant_list[lemin->nb_ant - 1]->pos_id != -1)
            my_putchar('\n');
    }
}