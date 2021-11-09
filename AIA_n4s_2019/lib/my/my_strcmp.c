/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** my_strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int diff = 0;
    int nb = 0;

    for (; s1[nb] == s2[nb] && s1[nb] != 0 && s2[nb] != 0; nb++);
    diff = s1[nb] - s2[nb];
    return diff;
}
