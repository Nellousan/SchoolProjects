/*
** EPITECH PROJECT, 2020
** my_array
** File description:
** a
*/

#include <stdlib.h>
#include "my.h"
#include "a_malloc.h"

int my_array_size(char **array)
{
    int i = 0;
    for (i = 0; array[i] != NULL; i++);
    return i;
}

int my_str_to_array_words(char *str, int len)
{
    int words = 0;
    words += (str[0] != '\0') ? 1 : 0;
    for (int i = 1; i < len; i++)
        words += (str[i] != '\0' && str[i - 1] == '\0') ? 1 : 0;
    return words;
}

char **my_str_to_array(char *str)
{
    int words = 0;
    int j = 0;
    char **array;
    int len = my_strlen(str);
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = (str[i] == ' ' || str[i] == '\t') ? '\0' : str[i];
    words = my_str_to_array_words(str, len);
    if (words == 0)
        return NULL;
    array = a_malloc(sizeof(char *) * (words + 1));
    if (str[0] != '\0') {
        array[0] = &str[0];
        j++;
    } for (int i = 1; i < len; i++)
        if (str[i] != '\0' && str[i - 1] == '\0') {
            array[j] = &str[i];
            j++;
        }
    array[j] = NULL;
    return array;
}
