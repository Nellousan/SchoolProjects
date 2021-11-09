/*
** EPITECH PROJECT, 2019
** my_sort_word array
** File description:
** sort ascii order tab
*/

#include <stdlib.h>
#include <stddef.h>

char *my_strdup(char const *str);

int my_arraylen(char const **tab)
{
    size_t i = 0;
    for (i; tab[i] != NULL; i++);
    return i;
}

char **my_arraydup(char * const *tab)
{
    char **buffer = malloc(sizeof(char *) * (my_arraylen(tab) + 1));
    for (size_t i = 0; tab[i] != NULL; i++)
        buffer[i] = my_strdup(tab[i]);
    return buffer;
}

int my_sort_word_array(char **tab)
{
    char **buffer = my_arraydup(tab);    
    size_t k = 0;
    for (size_t i = 0; i < 178; i++) {
        for (size_t j = 0; buffer[j] != NULL; j++) {
            if (buffer[j][0] == i) {
                tab[k] = buffer[j];
                k++;
            }
        }
    }
    return 0;
}
