/*
** EPITECH PROJECT, 2020
** verif
** File description:
** need
*/

#include "my.h"
#include "get_next_line.h"
#include "n4s.h"

bool my_strcomp(char *str, char *str2)
{
    for (size_t i = 0; str[i]; i++) {
        if (str[i] != str2[i]) {
            return false;
        }
    }
    return true;
}

static bool my_strncomp(char *str, char *str2, size_t i)
{
    for (size_t j = 0; str[i] || str2[j]; j++, i++) {
        if (str[i] != str2[j]) {
            return false;
        }
    }
    return true;
}

bool verif_end(char *str)
{
    size_t i = 0;

    for (i = 0; str[i]; i++) {
        if (str[i] == 'T')
            break;
    }
    return my_strncomp(str, "Track Cleared\0", i);
}