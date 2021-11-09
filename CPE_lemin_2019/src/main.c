/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** main
*/

#include "../include/my.h"
#include "../include/lemin.h"
#include "../include/get_next_line.h"

void find_room(lemin_t *lemin)
{
    for (size_t i = 0; lemin->anthill[i]; i++) {
        if (my_strcomp(lemin->anthill[i], "##start") == true)
            lemin->start = cp_room(lemin->anthill[i + 1]);
        if (my_strcomp(lemin->anthill[i], "##end") == true)
            lemin->end = cp_room(lemin->anthill[i + 1]);
    }
}

int find_nb(lemin_t * lemin)
{
    int nb = 0;

    if (lemin->anthill[0][0] == '#') {
        nb = my_atoi(lemin->anthill[1]);
    }
    else {
        nb = my_atoi(lemin->anthill[0]);
    }
    return nb;
}

void setup_id(lemin_t *lemin)
{
    node_t *start = find_node(lemin, cpdelim(&lemin->start, ' ', 0));
    node_t *end = find_node(lemin, cpdelim(&lemin->end, ' ', 0));
    lemin->start_id = start->id;
    lemin->end_id = end->id;
    return;
}

int print_nodes(lemin_t *lemin)
{
    my_printf("start : %d\nend : %d\n", lemin->start_id, lemin->end_id);
    for (int i = 0; NODE[i] != NULL; i++) {
        my_printf("Node %d\n", i);
        my_printf("res = %d\n", NODE[i]->result);
        my_printf("nb_links = %d\n", NODE[i]->nb_links);
    }
    return 0;
}

int main(int ac, char **av)
{
    lemin_t *lemin = malloc(sizeof(lemin_t));

    if (ac != 1) {
        return 84;
    }
    read_anthill(lemin);
    if (error_anthill(lemin) == true) {
        return 84;
    }
    parse_lemin(lemin);
    find_room(lemin);
    setup_id(lemin);
    lemin->nb_ant = find_nb(lemin);
    lemin->ant_list = ant_list_init(lemin);
    algo(count_node(lemin), lemin);
    lemin->solution = reverse_all_tab(NODE[START]->nb_links, SOLUT);
    display(lemin);
    road(lemin);
    return 0;
}
