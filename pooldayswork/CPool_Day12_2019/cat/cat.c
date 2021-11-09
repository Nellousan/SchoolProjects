/*
** EPITECH PROJECT, 2019
** cat
** File description:
** display content of file(s)
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

int cat_params(int argc, char **argv)
{
    int fd = 0;
    char buffer[2048];
    int size;
    for (int i = 1; argv[i] != NULL; i++) {
        size = 1;
        fd = open(argv[i], O_RDONLY);
        if (fd == -1) {
            my_putstr("Error while opening file ");
            my_putstr(argv[i]);
            return 1;
        }
        while (size != 0) {
            size = read(fd, buffer, 2047);
            buffer[size] = '\0';
            my_putstr(buffer);
        }
    }
    close(fd);
    return 0;
}

int cat_pipe(void)
{
    char buffer[2048];
    int size = 1;
    while (size != 0) {
        size = read(0, buffer, 2047);
        buffer[size] = '\0';
        my_putstr(buffer);
    }
    return 0;
}
