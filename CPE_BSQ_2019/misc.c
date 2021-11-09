/*
** EPITECH PROJECT, 2019
** misc funcs
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

int move_map_ptr(char **map)
{
    int i = 0;
    for (; (*map)[i] != '\n'; i++)
        if ((*map)[i] == '\0')
            return -1;
    *map += i + 1;
    return i + 1;
}

int get_line_len(char *map)
{
    int i = 0;
    for (; map[i] != '\n'; i++);
    return i + 1;
}

int get_ret_count(char *map)
{
    int j = 1;
    for (int i = 0; map[i] != '\0'; i++)
        j = (map[i] == '\n') ? j + 1 : j;
    return j;
}
