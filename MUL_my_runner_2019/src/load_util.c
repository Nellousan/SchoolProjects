/*
** EPITECH PROJECT, 2019
** game load utility functions
** File description:
** 
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "my_runner.h"

char *file_load(char *filepath)
{
    char *buffer = malloc(sizeof(char) * 2048);
    int fd = open(filepath, O_RDONLY);
    int size = 0;
    if (fd == -1) {
        free(buffer);
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
    for (; (*str)[i] != c; i++);
    copy = malloc(sizeof(char) * i + 1);
    for (i = 0; (*str)[i] != c; i++)
        copy[i] = (*str)[i];
    copy[i] = '\0';
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
    free(str);
    return nb;
}

int get_ret_count(char *str)
{
    int ret_cnt = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n')
            ret_cnt++;
    return ret_cnt;
}

sfIntRect extract_rect(char *str)
{
    char *str_c = str;
    sfIntRect rect;
    rect.left = char_to_int(copy_until(&str, ','));
    rect.top = char_to_int(copy_until(&str, ','));
    rect.width = char_to_int(copy_until(&str, ','));
    rect.height = char_to_int(copy_until(&str, '\0'));
    free(str_c);
    return rect;
}
