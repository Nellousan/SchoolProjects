/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** my_strncpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int value = 0;

    for (value = 0; src[value] != '\0'; value++)
        if (value < n)
            dest[value] = src[value];
    dest[value] = '\0';
    return (dest);
}
