/*
** EPITECH PROJECT, 2020
** selector
** File description:
** c
*/

#include "fasta.h"

int selector_b(fasta_t *fasta)
{
    int ret = 0;
    switch (MODE) {
    case 6:
        amino(fasta);
        break;
    case 7:
        seqal(fasta);
        break;
    default:
        ret = 84;
    }
    return ret;
}

int selector(fasta_t *fasta)
{
    switch (MODE) {
    case 1:
        dna(fasta);
        break;
    case 2:
        rna(fasta);
        break;
    case 3:
        revcomp(fasta);
        break;
    case 4:
        kmers(fasta);
        break;
    case 5:
        codseq(fasta);
        break;
    default:
        return selector_b(fasta);
    }
    return 0;
}
