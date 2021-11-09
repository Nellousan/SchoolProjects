/*
** EPITECH PROJECT, 2020
** fasta
** File description:
** h
*/

#ifndef FASTA_H
#define FASTA_H

#include <stdbool.h>

#define FUKLANORM1 str1[i] = SEQS[0][y - 1];str2[i] = SEQS[1][x - 1];i++;y--;x--
#define FUKLANORM2 str1[i] = '-';str2[i] = SEQS[1][x - 1];i++;x--
#define FUKLANORM3 str1[i] = SEQS[0][y - 1];str2[i] = '-';i++;y--

typedef struct fasta {
    char **sequences;
    char **names;
    int mode;
    int kmers;
}fasta_t;

#define NAMES fasta->names
#define SEQS fasta->sequences
#define MODE fasta->mode
#define KMERS fasta->kmers

void append(char ***tab, char *str, int list, bool dupsec);
fasta_t *get_fasta(int argc, char **argv);
char *astrcat(char *str1, char *str2, int list);
bool is_dna(char c);
void to_uppercase(char *str);
int my_atoi(char *str);
bool is_seq(char *str, char *seq);
void sort_tab(char **tab);
void reverse(char *str);
bool is_number(char *str);

int selector(fasta_t *fasta);
void dna(fasta_t *fasta);
void rna(fasta_t *fasta);
char **revcomp(fasta_t *fasta);
void kmers(fasta_t *fasta);
char **codseq(fasta_t *fasta);
void amino(fasta_t *fasta);
void seqal(fasta_t *fasta);

#endif
