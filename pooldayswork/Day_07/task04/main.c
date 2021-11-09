/*
** EPITECH PROJECT, 2019
** retieve & print arguments
** File description:
** 
*/
#include <stddef.h>

int my_putstr(char const *str);

int main(int argc, char **argv)
{
    for(size_t i = 0; i < argc; i++) {
        my_putstr(argv[i]);
        my_putstr("\n");
    }
}
