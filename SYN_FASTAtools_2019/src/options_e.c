/*
** EPITECH PROJECT, 2020
** options d 
** File description:
** c
*/

#include "fasta.h"
#include "my.h"
#include "a_malloc.h"

int **init_mat(char *str1, char *str2)
{
    int len1 = my_strlen(str1) + 1;
    int len2 = my_strlen(str2) + 1;
    int **mat = a_malloc(sizeof(int *) * len1);
    for (int i = 0; i < len1; i++) {
        mat[i] = a_malloc(sizeof(int) *len2);
        for (int j = 0; j < len2; j++)
            mat[i][j] = 0;
    }
    for (int i = 0; i < len1; i++)
        mat[i][0] = i * -4;
    for (int i = 0; i < len2; i++)
        mat[0][i] = i * -4;
    return mat;
}

int max(int nb1, int nb2, int nb3)
{
    nb1 = (nb2 > nb1) ? nb2 : nb1;
    nb1 = (nb3 > nb1) ? nb3 : nb1;
    return nb1;
}

void cmat(fasta_t *fasta, int **mat)
{
    int len1 = my_strlen(SEQS[0]) + 1;
    int len2 = my_strlen(SEQS[1]) + 1;
    int le;
    int t;
    int tl;
    for (int i = 1; i < len1; i++) {
        for (int j = 1; j < len2; j++) {
            le = mat[i][j - 1] - 1;
            t = mat[i - 1][j] - 1;
            tl = (SEQS[0][i - 1] == SEQS[1][j - 1]) ? mat[i - 1][j - 1] + 1 :
            mat[i - 1][j - 1] - 1;
            mat[i][j] = max(le, t, tl);
        }
    }
    return;
}

void seqal(fasta_t *fasta)
{
    int **mat = init_mat(SEQS[0], SEQS[1]);
    cmat(fasta, mat);
    my_putnbr(mat[my_strlen(SEQS[0])][my_strlen(SEQS[1])]);
    write(1, "\n", 1);
    return;
}
