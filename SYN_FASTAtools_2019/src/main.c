/*
** EPITECH PROJECT, 2020
** main
** File description:
** c
*/

#include "fasta.h"
#include "a_malloc.h"

int main(int argc, char **argv)
{
    fasta_t *fasta = get_fasta(argc, argv);
    if (!fasta)
        return 84;
    selector(fasta);
    a_malloc(A_MALLOC_FREE | A_LIST(1));
    a_malloc(A_MALLOC_FREE | A_LIST(0));
    return 0;
}
