/*
** EPITECH PROJECT, 2020
** load_util.c
** File description:
** a
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "a_malloc.h"
#include "navy.h"

char *file_load(char *filepath)
{
    char *buffer = a_malloc(sizeof(char) * 2048);
    int fd = open(filepath, O_RDONLY);
    int size = 0;
    if (fd == -1) {
        my_printf("Error: %s is invalid file path", filepath);
        return NULL;
    }
    size = read(fd, buffer, 2047);
    buffer[size] = '\0';
    close(fd);
    return buffer;
}

char *copy_until(char **str, char c)
{
    int i = 0;
    char *copy;
    for (; (*str)[i] != c && (*str)[i] != '\0'; i++);
    copy = a_malloc(sizeof(char) * i + 1);
    for (i = 0; (*str)[i] != c && (*str)[i] != '\0'; i++)
        copy[i] = (*str)[i];
    copy[i] = '\0';
    if ((*str)[i] == '\0')
        (*str) += i;
    else
        (*str) += i + 1;
    return copy;
}

int char_to_int(char *str)
{
    int neg = 0;
    int nb = 0;
    if (str[0] == '-') {
        str++;
        neg = 1;
    }
    for (int i = 0; str[i] != '\0'; i++)
        nb += DEC(str[i]) * my_pow(10, my_strlen(str) - (i + 1));
    if (neg) {
        nb = -nb;
        str--;
    }
    return nb;
}
