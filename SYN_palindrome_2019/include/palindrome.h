/*
** EPITECH PROJECT, 2020
** pal
** File description:
** h
*/

#ifndef PALINDROME
#define PALINDROME

#include <stdbool.h>
#include <stddef.h>

/************** DEFINES ***************/

#define NB pal->nb
#define SNB pal->snb
#define PAL pal->pal
#define SPAL pal->spal
#define IMAX pal->imax
#define IMIN pal->imin
#define BASE pal->base

#define DEC(x) ((x) - '0')

/************** STRUCTS ***************/

typedef struct pal {
    int nb;
    int pal;
    int imax;
    int imin;
    int base;
    char *snb;
    char *spal;
}pal_t;

/*************** PROTO ****************/

pal_t *get_opts(int argc, char **argv);
pal_t *init_pal(void);

int my_atoi(char *str);
char *my_itoa(int nb);
void reverse(char *str);
bool arg_validity(pal_t *pal);
char *convert_base_str(int nb, int base);
int convert_base_int(char *str, int base);

void iterate_nb(pal_t *pal, int nb);
void iterate_pal(pal_t *pal);
bool is_palindrome(pal_t *pal, int nb);

void display_help(void);

int turnover(pal_t *pal, int nb);

/**************************************/

#endif
