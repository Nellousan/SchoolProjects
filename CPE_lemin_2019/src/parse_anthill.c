/*
** EPITECH PROJECT, 2020
** parse
** File description:
** anthill
*/

#include "lemin.h"
#include "a_malloc.h"
#include "my.h"

node_t *find_node(lemin_t *lemin, char *str)
{
    for (int i = 0; NODE[i] != NULL; i++) {
        if (!my_strcmp(NODE[i]->name, str))
            return NODE[i];
    }
    return NULL;
}

static void add_link(node_t *node, node_t *add)
{
    int i = 0;
    for (i = 0; node->links[i] != NULL; i++);
    node->links[i] = add;
    node->links[i + 1] = NULL;
    return;
}

static void link_nodes(lemin_t *lemin, char *str)
{
    char *noden1 = cpdelim(&str, '-', 0);
    char *noden2 = cpdelim(&str, '\n', 0);
    node_t *node1 = find_node(lemin, noden1);
    node_t *node2 = find_node(lemin, noden2);
    add_link(node1, node2);
    add_link(node2, node1);
    return;
}

static node_t *node_create(char *str, int n, int links)
{
    node_t *node = a_malloc(sizeof(node_t) | A_LIST(1));
    node->id = n;
    node->name = cpdelim(&str, ' ', 1);
    node->result = 0;
    node->from = 0;
    node->links = a_malloc(sizeof(node_t *) * links | A_LIST(1));
    node->links[0] = NULL;
    return node;
}

void parse_lemin(lemin_t *lemin)
{
    int links = 0;
    int rooms = 0;
    int n = 0;
    int lc = 0;
    count(lemin, &rooms, &links);
    NODE = a_malloc(sizeof(node_t *) * (rooms + 1) | A_LIST(1));
    for (int i = 0; ANTHILL[i] != NULL; i++) {
        if (is_room(ANTHILL[i])) {
            NODE[n] = node_create(ANTHILL[i], n, links);
            n++;
        }
        if (is_link(ANTHILL[i]))
            link_nodes(lemin, ANTHILL[i]);
    }
    NODE[n] = NULL;
    for (int i = 0; NODE[i] != NULL; i++) {
        for (lc = 0; NODE[i]->links[lc] != NULL; lc++);
        NODE[i]->nb_links = lc;
    }
    return;
}
