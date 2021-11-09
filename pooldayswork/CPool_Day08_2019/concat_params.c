/*
** EPITECH PROJECT, 2019
** concat_params
** File description:
** concat params in a single string
*/

#include <stddef.h>
#include <stdlib.h>

int my_strlen(char const *str);

char *concat_params(int argc, char **argv)
{
    size_t size = 0;
    size_t j = 0;
    size_t k = 0;
    for (size_t i = 0; i < argc; i++) {
        size += my_strlen(argv[i]);
    }
    char *buffer = malloc(size);
    for (size_t i = 0; i < argc; i++) {
        for (j = 0; j < my_strlen(argv[i]); j++) {
            buffer[k] = argv[i][j];
            k++;
        }
        buffer[k] = '\n';
        k++;
    }
    return buffer;
}
