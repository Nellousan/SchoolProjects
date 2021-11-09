/*
** EPITECH PROJECT, 2020
** Getnextline
** File description:
** .h
*/

#ifndef READ_SIZE
#define READ_SIZE 4
#endif

#include "stdlib.h"
#include "stddef.h"

int reader_in_buffer(int *index, int *size, char *reader, char *buffer);
char *get_next_line(int fd);
