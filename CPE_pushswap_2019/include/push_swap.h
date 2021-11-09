/*
** EPITECH PROJECT, 2019
** push_swap
** File description:
** 
*/

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

/************** DEFINES ***************/

#define ABS(value) ((value) < 0) ? -(value) : (value)
#define DEC(value) ((value) - '0')

/************** STRUCTS ***************/

typedef struct list {
    int is_start;
    int val;
    void *prev;
    void *next;
} list_t;

/************* LIST INITS *************/

list_t *list_create(int val, void *prev, void *next);
list_t *argv_to_list(int argc, char **argv);

/*************** MISC. ****************/

void display_list(list_t *start);
int char_to_int(char *str);

/************ QUEUE OP. ***************/

void swap(list_t **start);
void rotate(list_t **start);

/************ LIST SORT ***************/

int is_sorted(list_t *list);
void sort_loop(list_t **start);

/**************************************/

#endif
