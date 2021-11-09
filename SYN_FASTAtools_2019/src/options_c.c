/*
** EPITECH PROJECT, 2020
** options c
** File description:
** c
*/

#include <unistd.h>
#include <stdlib.h>
#include "fasta.h"
#include "my.h"
#include "a_malloc.h"

bool is_seq(char *str, char *seq)
{
    for (int i = 0; seq[i] != '\0'; i++) {
        if (seq[i] != str[i])
            return false;
        if (str[i] == '\0')
            return false;
    }
    return true;
}

static void codseq_c(char *seq, char ***tab)
{
    int len = my_strlen(seq);
    for (int i = 0; i < len; i += 3) {
        if (is_seq(seq + i, "TAA") || is_seq(seq + i, "TAG") ||
        is_seq(seq + i, "TGA")) {
            seq[i] = '\0';
            append(tab, seq, 0, false);
            return;
        }
    }
}

static void codseq_b(char *seq, char ***tab)
{
    for (int i = 0; seq[i] != '\0'; i++) {
        if (is_seq(seq + i, "ATG"))
            codseq_c(my_strdup(seq + i), tab);
    }
    return;
}

char **codseq(fasta_t *fasta)
{
    char **tab = a_malloc(sizeof(char*));
    char **revcomps = revcomp(fasta);
    tab[0] = NULL;
    for (int i = 0; SEQS[i] != NULL && NAMES[i] != NULL; i++) {
        codseq_b(SEQS[i], &tab);
        codseq_b(revcomps[i], &tab);
    }
    sort_tab(tab);
    if (MODE == 5)
        for (int i = 0; tab[i] != NULL; i++)
            my_printf("%s\n", tab[i]);
    return tab;
}
