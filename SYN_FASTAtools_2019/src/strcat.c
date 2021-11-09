/*
** EPITECH PROJECT, 2020
** da
** File description:
** da
*/

#include "fasta.h"
#include "my.h"
#include "a_malloc.h"

char *astrcat(char *str1, char *str2, int list)
{
    int len;
    char *str;
    int i = 0;
    int j = 0;
    int len1 = (str1) ? my_strlen(str1) : 0;
    int len2 = (str2) ? my_strlen(str2) : 0;
    len = len1 + len2;
    str = a_malloc(sizeof(char) * (len + 1) | A_LIST(list));
    if (str1) {
        for (i = 0; str1[i] != '\0'; i++)
            str[i] = str1[i];
    }
    if (str2) {
        for (j = 0; str2[j] != '\0'; j++)
            str[i + j] = str2[j];
    }
    str[i + j] = '\0';
    return str;
}

bool is_number(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}
