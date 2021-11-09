/*
** EPITECH PROJECT, 2020
** miscellaneous functions
** File description:
** 
*/

#include <stdlib.h>
#include "my.h"
#include "my_ls.h"
#include "a_malloc.h"

int char_in_string(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return 1;
    return 0;
}

char *ls_strcat(char *str1, char *str2)
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

char *cat_dirpath_file(char *dirpath, char *file)
{
    char *res1 = ls_strcat(dirpath, "/");
    char *res2 = ls_strcat(res1, file);
    free(res1);
    return res2;
}
