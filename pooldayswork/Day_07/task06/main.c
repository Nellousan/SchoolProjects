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
    int buffer_tab[100];
    size_t k = 0;
    for(size_t i = 0; i < 178; i++) {
        for (size_t j = 0; j < argc; j++) { 
            if(argv[j][0] == i) {
                my_putstr(argv[j]);
                my_putstr("\n");
            }
        }
    }
}
