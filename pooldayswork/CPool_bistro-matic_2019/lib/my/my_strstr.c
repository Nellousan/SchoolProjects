/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** my_strstr
*/

char *my_strstr(char *str, char const *to_find)
{
    int value = 0;

    if (str[value] != '\0')
        value = 0;
    else
        return (0);
    while (to_find[value] != '\0' && str[value] != '\0') {
        if (to_find[value] != str[value])
            return (my_strstr(str + 1, to_find));
        value++;
    }
    return (str);
}
