/*
** EPITECH PROJECT, 2020
** complex options
** File description:
** c
*/

#include <stdlib.h>
#include "fasta.h"
#include "my.h"
#include "a_malloc.h"

bool is_sorted(char **tab)
{
    for (int i = 0; tab[i + 1] != NULL; i++)
        if (my_strcmp(tab[i], tab[i + 1]) == 1)
            return false;
    return true;
}

void sort_tab(char **tab)
{
    char *tmp;
    for (int i = 0; !is_sorted(tab); i = (tab[i + 2] == NULL) ? 0 : i + 1) {
        if (my_strcmp(tab[i], tab[i + 1]) == 1) {
            tmp = tab[i + 1];
            tab[i + 1] = tab[i];
            tab[i] = tmp;
        }
    }
    return;
}

void kmers(fasta_t *fasta)
{
    char *str;
    char **tab = a_malloc(sizeof(char*));
    tab[0] = NULL;
    for (int i = 0; SEQS[i] != NULL && NAMES[i] != NULL; i++) {
        while (my_strlen(SEQS[i]) >= KMERS) {
            str = my_astrdup(SEQS[i], 1);
            str[KMERS] = '\0';
            append(&tab, str, 0, true);
            SEQS[i]++;
        }
    }
    sort_tab(tab);
    for (int i = 0; tab[i] != NULL; i++)
        my_printf("%s\n", tab[i]);
    return;
}
