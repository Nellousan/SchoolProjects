/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** my_strcpy
*/

char *my_strcpy(char *dest, char const *src)
{
    int value = 0;

    for (value = 0; src[value] != '\0'; value++)
        dest[value] = src[value];
    dest[value] = '\0';
    return (dest);
}
