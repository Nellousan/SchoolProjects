/*
** EPITECH PROJECT, 2020
** get fasta
** File description:
** c
*/

#include "fasta.h"
#include "my.h"
#include "a_malloc.h"
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

static void clear_sequence(char **str)
{
    int count = 0;
    char *newstr;
    int i = 0;
    int j = 0;
    for (i = 0; (*str)[i] != '\0'; i++) {
        if (is_dna((*str)[i]))
            count++;
    }
    newstr = a_malloc(sizeof(char) * (count + 1) | A_LIST(1));
    for (i = 0; (*str)[i] != '\0'; i++) {
        if (is_dna((*str)[i])) {
            newstr[j] = (*str)[i];
            j++;
        }
    }
    newstr[j] = '\0';
    to_uppercase(newstr);
    (*str) = newstr;
    return;
}

static void clear_sequences(fasta_t *fasta)
{
    for (int i = 0; SEQS[i] != NULL; i++) {
        clear_sequence(&SEQS[i]);
    }
    return;
}

static void clear(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            return;
        }
    }
    return;
}

static void get_sequences(fasta_t *fasta)
{
    size_t n = 0;
    char *buffer = NULL;
    char *lbuffer = NULL;
    ssize_t size = getline(&buffer, &n, stdin);
    while (size > 0) {
        clear(buffer);
        if (buffer[0] == '>') {
            append(&NAMES, my_astrdup(buffer, 1), 1, false);
        } else {
            lbuffer = astrcat(lbuffer, buffer, 0);
        } if (buffer[0] == '>' && lbuffer) {
            append(&SEQS, my_astrdup(lbuffer, 1), 1, false);
            lbuffer = NULL;
        } free(buffer);
        buffer = NULL;
        size = getline(&buffer, &n, stdin);
    }
    append(&SEQS, my_astrdup(lbuffer, 1), 1, false);
    clear_sequences(fasta);
    return;
}

fasta_t *get_fasta(int argc, char **argv)
{
    fasta_t *fasta = a_malloc(sizeof(fasta_t));
    int len;
    if (argc < 2 || isatty(0))
        return NULL;
    MODE = my_atoi(argv[1]);
    if (MODE < 1 || MODE > 7)
        return NULL;
    if (MODE == 4) {
        if (argc < 3 || !is_number(argv[2]))
            return NULL;
        KMERS = my_atoi(argv[2]);
    } NAMES = a_malloc(sizeof(char*) | A_LIST(1));
    NAMES[0] = NULL;
    SEQS = a_malloc(sizeof(char*) | A_LIST(1));
    SEQS[0] = NULL;
    get_sequences(fasta);
    for (len = 0; SEQS[len] != NULL; len++);
    if (MODE == 7 && len != 2)
        return NULL;
    return fasta;
}
