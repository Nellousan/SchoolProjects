/*
** EPITECH PROJECT, 2020
** miscellaneous
** File description:
** s
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include "a_malloc.h"
#include "my.h"

int my_atoi(char *str)
{
    int neg = 0;
    int nb = 0;
    if (str[0] == '-') {
        str++;
        neg = 1;
    }
    for (int i = 0; str[i] != '\0'; i++)
        nb += (str[i] - '0') * my_pow(10, my_strlen(str) - (i + 1));
    if (neg) {
        nb = -nb;
        str--;
    }
    return nb;
}

char *cpdelim(char **str, char c)
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

char *mstrcat(char *str1, char *str2)
{
    char *res = a_malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 1));
    int i = 0;
    for (int j = 0; str1[j] != '\0'; i++, j++)
        res[i] = str1[j];
    for (int j = 0; str2[j] != '\0'; i++, j++)
        res[i] = str2[j];
    res[i] = '\0';
    return res;
}

char *file_load(char *filepath)
{
    char *buffer = a_malloc(sizeof(char) * 512);
    int fd = open(filepath, O_RDONLY);
    int size = 0;
    if (fd == -1) {
        my_printf("Error: %s is invalid file path", filepath);
        return NULL;
    }
    size = read(fd, buffer, 511);
    buffer[size] = '\0';
    close(fd);
    return buffer;
}
