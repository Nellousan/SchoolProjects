/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** strcuts
*/

#ifndef LEMIN_H
#define LEMIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>

/**************************************/

typedef struct node node_t;

typedef struct ant {
    int id;
    int pos_id;
}ant_t;

typedef struct node {
    int id;
    int from;
    int result;
    int nb_links;
    char *name;
    node_t **links;
}node_t;

typedef struct result {
    int id;
    int result;
}result_t;

typedef struct lemin {
    ant_t **ant_list;
    node_t **node_list;
    result_t *result;
    int start_id;
    int end_id;
    int nb_ant;
    int i;
    char **anthill;
    char ***solution;
    char *start;
    char *end;
}lemin_t;

/**************************************/

#define ANT lemin->ant_list
#define ANTHILL lemin->anthill
#define NODE lemin->node_list
#define RES lemin->result
#define SOLUT lemin->solution
#define START lemin->start_id
#define END lemin->end_id
#define I lemin->i

/**************************************/

char *my_strcp(char *str);
bool my_strcomp(char *str, char *s);
void read_anthill(lemin_t *lemin);
char *cp_room(char *str);
bool error_anthill(lemin_t *lemin);
void display(lemin_t *lemin);
bool verif_room(char *str);
bool verif_tunnel(char *str);
bool verif_nb_ant(lemin_t *lemin);
size_t nb_links(lemin_t *lemin, char *name);
node_t *find_node(lemin_t *lemin, char *str);
void road(lemin_t *lemin);

void parse_lemin(lemin_t *lemin);
bool is_room(char *str);
bool is_link(char *str);
void count(lemin_t *lemin, int *rooms, int *links);
int my_atoi(char *str);
char *cpdelim(char **str, char c, int list);
int count_node(lemin_t *lemin);
ant_t **ant_list_init(lemin_t *lemin);

/**************************************/

int *init_tab_int(int nb_max);
result_t init_result(int id, int nb);
result_t *init_tab_result(int nb, int node_max);
char ***init_tab_char(int max, int node_max);
void algo(int node_max, lemin_t *lemin);
void init_all(int node_max, int **from, lemin_t *lemin);
char ***reverse_all_tab(int nb_links, char ***tab);

/**************************************/

#endif
