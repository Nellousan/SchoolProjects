/*
** EPITECH PROJECT, 2019
** map funcs
** File description:
** 
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "bsq.h"

char *load_map(char *path)
{
    int fd = open(path, O_RDONLY);
    if (fd == -1)
        return NULL;
    struct stat *fstats = malloc(sizeof(struct stat));
    fstat(fd, fstats);
    char *buffer = malloc(sizeof(char) * (fstats->st_size + 1));
    int size = read(fd, buffer, fstats->st_size);
    buffer[size] = '\0';
    close(fd);
    return buffer;
}
