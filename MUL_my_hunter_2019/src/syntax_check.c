/*
** EPITECH PROJECT, 2019
** syntax check
** File description:
** 
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my.h"
#include "my_hunter.h"

void print_help(void)
{
    char *buffer = malloc(sizeof(char) * 2048);
    int size = 0;
    int fd = open("help", O_RDONLY);
    size = read(fd, buffer, 2047);
    buffer[size] = '\0';
    my_putstr(buffer);
    free(buffer);
    return;
}

int syntax_check(int argc, char **argv)
{
    if (argc < 2) {
        my_putstr("No arguments, use -h for help.\n");
        return 84;
    }
    if (argv[1][0] == '-' && argv[1][1] == 'h' && my_strlen(argv[1]) == 2) {
        print_help();
        return 84;
    }
    return 0;
}
