/*
** EPITECH PROJECT, 2020
** options
** File description:
** c
*/

#include <unistd.h>
#include "fasta.h"
#include "my.h"
#include "a_malloc.h"

void dna(fasta_t *fasta)
{
    for (int i = 0; SEQS[i] != NULL && NAMES[i] != NULL; i++) {
        my_printf("%s\n%s\n", NAMES[i], SEQS[i]);
    }
    return;
}

void rna(fasta_t *fasta)
{
    char c;
    for (int i = 0; SEQS[i] != NULL && NAMES[i] != NULL; i++) {
        my_printf("%s\n", NAMES[i]);
        for (int j = 0; SEQS[i][j] != '\0'; j++) {
            c = (SEQS[i][j] == 'T') ? 'U' : SEQS[i][j];
            write(1, &c, 1);
        }
        write(1, "\n", 1);
    }
    return;
}

char **revcomp(fasta_t *fasta)
{
    char c;
    char *str;
    int j;
    int k;
    char **tab = a_malloc(sizeof(char *));
    tab[0] = NULL;
    for (int i = 0; SEQS[i] != NULL && NAMES[i] != NULL; i++) {
        if (MODE == 3)
            my_printf("%s\n", NAMES[i]);
        str = a_malloc(sizeof(char) * (my_strlen(SEQS[i]) + 1));
        for (j = my_strlen(SEQS[i]) - 1, k = 0; j >= 0; j--, k++) {
            c = SEQS[i][j];
            c = (c == 'T') ? 'A' : (c == 'A') ? 'T' : (c == 'G') ? 'C' :
            (c == 'C') ? 'G' : c;
            str[k] = c;
        } str[k] = '\0';
        append(&tab, str, 0, false);
        if (MODE == 3)
            my_printf("%s\n", str);
    } return tab;
}
