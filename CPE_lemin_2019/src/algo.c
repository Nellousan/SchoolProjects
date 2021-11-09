/*
** EPITECH PROJECT, 2020
** Lemin
** File description:
** Algo
*/

#include "../include/my.h"
#include "../include/lemin.h"

static int end(int node_max, int save_nb, int **from, lemin_t *lemin)
{
    static int p = 0;
    size_t j = 0;
    int count = 0;

    if (save_nb == END) {
        for (size_t y = save_nb; NODE[y]->id != START; j++) {
            SOLUT[p][j] = NODE[y]->name;
            (*from)[NODE[y]->id] = NODE[y]->id;
            y = NODE[y]->from;
        } SOLUT[p][j] = NODE[START]->name; SOLUT[p][j + 1] = NULL; j = 0;
        for (size_t y = 0; j != (size_t)NODE[START]->nb_links; y++) {
            count += (NODE[START]->links[j]->id == (*from)[y]) ? 1 : 0;
            j += (NODE[START]->links[j]->id == (*from)[y]) ? 1 : 0;
            y = (y == (size_t)node_max) ? 0 : y;
        } p++; if (count == NODE[START]->nb_links)
            return -1;
    } else {
        I = save_nb;
        RES[save_nb] = init_result(save_nb, 1000000);
        (*from)[NODE[I]->id] = NODE[I]->id;
    } return I;
}

static void check_result(int node_max, int *min,
size_t *save_nb, lemin_t *lemin)
{
    for (size_t y = 0; y < (size_t)node_max;) {
        if (RES[y].result < (*min)) {
            (*min) = RES[y].result;
            (*save_nb) = NODE[lemin->i]->links[y]->id;
            y = 0;
        } else
            y++;
    }
}

static int check_min(size_t count, size_t *save_nb,
result_t *result, node_t *node)
{
    int min = node->links[(*save_nb)]->result;

    for (size_t y = 0; y < count;) {
        if (min > node->links[y]->result) {
            min = node->links[y]->result;
            (*save_nb) = y;
            y = 0;
        } else
            y++;
    }
    for (size_t y = 0; y < count; y++)
        if (y != (*save_nb))
            result[node->links[y]->id] =
            init_result(node->links[y]->id, node->links[y]->result);
    return min;
}

static int check_road(int node_max, size_t *count, int *from, node_t *node)
{
    size_t count_nb = 0;
    size_t save_nb = 0;

    (*count) = 0;
    for (size_t i = 0; i < (size_t)node->nb_links; i++) {
        for (size_t y = 0; y < (size_t)node_max; y++) {
            count_nb += (from[y] != node->links[i]->id) ? 1 : 0;
            node->links[i]->result +=
            (count_nb == (size_t)node_max) ? 1 + node->result : 0;
            (*count) += (count_nb == (size_t)node_max) ? 1 : 0;
            save_nb = (count_nb == (size_t)node_max) ? i : save_nb;
        }
    }
    return save_nb;
}

void algo(int node_max, lemin_t *lemin)
{
    size_t y = 0;
    size_t count = 0;
    size_t save_nb = 0;
    int min = 0;
    int *from;

    init_all(node_max, &from, lemin);
    while (1) {
        y = check_road(node_max, &count, from, NODE[lemin->i]);
        min = NODE[lemin->i]->links[y]->result;
        save_nb = y;
        if (count > 1) {
            min = check_min(count, &save_nb, RES, NODE[lemin->i]);
            check_result(node_max, &min, &save_nb, lemin);
        } else
            save_nb = NODE[lemin->i]->links[y]->id;
        NODE[save_nb]->from = NODE[lemin->i]->id;
        lemin->i = end(node_max, save_nb, &from, lemin);
        if (lemin->i == -1)
            break;
    }
}
