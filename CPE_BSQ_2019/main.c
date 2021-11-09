/*
** EPITECH PROJECT, 2019
** main bsq
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

int main(int argc, char **argv)
{
    if (argc != 2)
        return 84;
    char *map = load_map(argv[1]);
    if (map == NULL)
        return 84;
    sq_vect_t *big_sq = sq_init();
    int success_status = bsq(map, big_sq);
    free(map);
    if (success_status == 84)
        return 84;
    return 0;
}
