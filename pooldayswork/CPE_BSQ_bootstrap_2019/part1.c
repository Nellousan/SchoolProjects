/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** 
*/

#include <stdlib.h>
#include "my.h"

void fs_understand_return_of_read(int fd, char *buffer, int size)
{
    int buff_size = read(fd, buffer, size);
    if (buff_size == -1)
        my_putstr("read failed\n");
    if (buff_size == 0)
        my_putstr("read has nothing more to read\n");
    if (buff_size < size)
        my_putstr("read didn't complete the entire buffer_n");
    if (buff_size == size)
        my_putstr("read completed the entire buffer\n");
    return;
}

int fs_open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    if (fd == -1)
        my_putstr("FAILURE\n");
    else
        my_putstr("SUCCESS\n");
    return fd;
}

void fs_cat_500_bytes(char const *filepath)
{
    char *buffer = malloc(sizeof(char) * 500);
    int fd = fs_open_file(filepath);
    fs_understand_return_of_read(fd, buffer, 500);
    for (int i = 0; i < 500; i++)
        my_putchar(buffer[i]);
    close(fd);
    return;
}

void fs_cat_x_bytes(char const *filepath, int x)
{
    char *buffer = malloc(sizeof(char) * x);
    int fd = fs_open_file(filepath);
    fs_understand_return_of_read(fd, buffer, x);
    for (int i = 0; i < x; i++)
        my_putchar(buffer[i]);
    close(fd);
    return; 
}

void fs_print_first_line(char const *filepath)
{
    char *buffer = malloc(sizeof(char) * 512);
    int fd = fs_open_file(filepath);
    fs_understand_return_of_read(fd, buffer, 512);
    for (int i = 0; buffer[i] != '\n', i++)
        my_putchar(buffer[i]);
    close(fd);
    return;
}

int main(int argc, char **argv)
{
    
}
