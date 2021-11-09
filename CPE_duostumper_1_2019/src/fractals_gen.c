/*
** EPITECH PROJECT, 2020
** fractals
** File description:
** generation
*/

#include <stdlib.h>
#include "my.h"
#include "a_malloc.h"
#include "fractals_s.h"
#include "fractals.h"
#include "word_array.h"

static int get_node_count(char **chain)
{
    int node_c = 0;
    
    for (size_t i = 0; chain[i] != NULL; i++) {
        node_c += my_strlen(chain[i]);
    }
    return node_c;
}

static int get_node_chain(int node, char **chain)
{
    int count = 0;
    int j = 0;
    int i = 0;
    
    while (count != node) {
        count++;
        i++;
        if (chain[j][i] == '\0') {
            i = 0;
            j++;
        }
    }
    if (chain[j][i] == '#')
        return 0;
    else
        return 1;
}

static char **fractal_array_init(int scale, char ***chains)
{
    int width = my_compute_power_rec(my_strlen(chains[0][0]), scale);
    int height = my_compute_power_rec(word_array_len(chains[0]), scale);
    char **frac = a_malloc(sizeof(char *) * (height + 1));
    int j = 0;
    int i = 0;
    
    for (i = 0; i < height; i++) {
        frac[i] = a_malloc(sizeof(char) * (width + 1));
        for (j = 0; j < width; j++)
            frac[i][j] = '.';
        frac[i][j] = '\0';
    }
    frac[i] = NULL;
    return frac;
}

char **fractal_gen(int chain, int scale, char ***chains)
{
    int width = my_compute_power_rec(my_strlen(chains[0][0]), scale - 1);
    int height = my_compute_power_rec(word_array_len(chains[0]), scale - 1);
    int node_h = my_strlen(chains[0][0]);
    int node_w = word_array_len(chains[0]);
    int node_c = get_node_count(chains[0]);
    char **frac = fractal_array_init(scale, chains);
    char **tmp = NULL;
    vect2u_t pos;
    
    if (scale <= 1)
        return chains[chain];
    for (int i = 0; i < node_c; i++) {
        pos = VECT2U(i % node_w * width, i / node_h * height);
        if (chain == 1)
            tmp = fractal_gen(1, scale - 1, chains);
        else
            tmp = fractal_gen(get_node_chain(i, chains[0]), scale - 1, chains);
        fill_2d_tab(pos, frac, tmp);
    }
    return frac;
}
