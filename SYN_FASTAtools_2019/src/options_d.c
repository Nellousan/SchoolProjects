/*
** EPITECH PROJECT, 2020
** options d
** File description:
** c
*/

#include <stddef.h>
#include "fasta.h"
#include "my.h"
#include "a_malloc.h"

static char lfind_c(char *str)
{
    char c = '\0';
    if (is_seq(str, "TCT") || is_seq(str, "TCC") || is_seq(str, "TCA") ||
        is_seq(str, "TCG") || is_seq(str, "AGT") || is_seq(str, "AGC"))
        c = 'S';
    if (is_seq(str, "ACT") || is_seq(str, "ACC") || is_seq(str, "ACA") ||
    is_seq(str, "ACG"))
        c = 'T';
    if (is_seq(str, "GTT") || is_seq(str, "GTC") || is_seq(str, "GTA") ||
    is_seq(str, "GTG"))
        c = 'V';
    if (is_seq(str, "TGG"))
        c = 'W';
    if (str[0] == 'N' || str[1] == 'N' || str[2] == 'N')
        c = 'X';
    if (is_seq(str, "TAT") || is_seq(str, "TAC"))
        c = 'Y';
    return c;
}

static char lfind_b(char *str)
{
    char c = '\0';
    if (is_seq(str, "AAA") || is_seq(str, "AAG"))
        c = 'K';
    if (is_seq(str, "TTA") || is_seq(str, "TTG") || is_seq(str, "CTT") ||
        is_seq(str, "CTC") || is_seq(str, "CTA") || is_seq(str, "CTG"))
        c = 'L';
    if (is_seq(str, "ATG"))
        c = 'M';
    if (is_seq(str, "AAT") || is_seq(str, "AAC"))
        c = 'N';
    if (is_seq(str, "CCT") || is_seq(str, "CCC") || is_seq(str, "CCA") ||
    is_seq(str, "CCG"))
        c = 'P';
    if (is_seq(str, "CAA") || is_seq(str, "CAG"))
        c = 'Q';
    if (is_seq(str, "AGA") || is_seq(str, "AGG") || is_seq(str, "CGT") ||
    is_seq(str, "CGC") || is_seq(str, "CGA") || is_seq(str, "CGG"))
        c = 'R';
    return (c == '\0') ? lfind_c(str) : c;
}

static char lfind(char *str)
{
    char c = '\0';
    if (is_seq(str, "GCT") || is_seq(str, "GCC") || is_seq(str, "GCA") ||
    is_seq(str, "GCG"))
        c = 'A';
    if (is_seq(str, "TGT") || is_seq(str, "TGC"))
        c = 'C';
    if (is_seq(str, "GAT") || is_seq(str, "GAC"))
        c = 'D';
    if (is_seq(str, "GAA") || is_seq(str, "GAG"))
        c = 'E';
    if (is_seq(str, "TTT") || is_seq(str, "TTC"))
        c = 'F';
    if (is_seq(str, "GGT") || is_seq(str, "GGC") || is_seq(str, "GGA") ||
    is_seq(str, "GGG"))
        c = 'G';
    if (is_seq(str, "CAT") || is_seq(str, "CAC"))
        c = 'H';
    if (is_seq(str, "ATT") || is_seq(str, "ATC") || is_seq(str, "ATA"))
        c = 'I';
    return (c == '\0') ? lfind_b(str) : c;
}

static char *find(char *seq)
{
    int amino_c = my_strlen(seq) / 3;
    char *str = a_malloc(sizeof(char) * (amino_c + 1));
    for (int i = 0; i < amino_c; i++)
        str[i] = lfind(seq + (i * 3));
    return str;
}

void amino(fasta_t *fasta)
{
    char **tab = codseq(fasta);
    char **a_tab = a_malloc(sizeof(char*));
    char *str;
    a_tab[0] = NULL;
    for (int i = 0; tab[i] != NULL; i++) {
        str = find(tab[i]);
        append(&a_tab, str, 0, false);
    }
    sort_tab(a_tab);
    for (int i = 0; a_tab[i] != NULL; i++)
        my_printf("%s\n", a_tab[i]);
    return;
}
