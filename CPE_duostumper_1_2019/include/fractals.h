/*
** EPITECH PROJECT, 2020
** CPE_duostumper_1_2019
** File description:
** fractals
*/

#ifndef FRACTALS_H_
#define FRACTALS_H_

#include "fractals_s.h"

#define VECT2U(x, y) (vect2u_t){x, y}

int syntax_check(int argc, char **argv);
int fractals(char **argv);
int fill_2d_tab(vect2u_t p, char **dest, char **src);
void my_putstr_error(char *str);
char **fractal_gen(int chain, int scale, char ***chains);

#endif
