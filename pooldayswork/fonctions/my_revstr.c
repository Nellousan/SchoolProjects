/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** reverse string
*/
#include <stdio.h>

int my_strlen(char const *str);

void copy_string(char *str, char *str2)
{
    int i = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        str2[i] = str[i];
    }
}

char *my_revstr(char *str)
{
    int str_length = my_strlen(str) - 1;
    char str2[30] = "";
    copy_string(str, str2);
    int i = 0;
    while (str_length + 1 != 0)
    {
        str[i] = str2[str_length];
        str_length--;
        i++;
    }
    return str;
}
