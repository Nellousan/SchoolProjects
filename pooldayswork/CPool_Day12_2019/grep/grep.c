/*
** EPITECH PROJECT, 2019
** grep
** File description:
** do grep
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

int print_line(char *str)
{
    for (int i = 0; str[i] != '\n' && str[i] != '\0'; i++)
        my_putchar(str[i]);
    my_putchar('\n');
}

int check_buffer(char *str, char *to_find)
{
        
}

int grep_params(char **argv)
{
    int fd = 0;
    int size;

    for (int i = 2; argv[i] != NULL; i++) {
        char buffer[2048];
        fd = open(argv[i], O_RDONLY);
        size = 1;
        if (fd == -1) {
            my_putstr("Error while opening file ");
            my_putstr(argv[i]);
            return 1;
        }
        while (size != 0) {
            size = read(fd, buffer, 2047);
            buffer[size] = '\0';
            check_buffer(buffer, argv[1]);
        }
    }
}
