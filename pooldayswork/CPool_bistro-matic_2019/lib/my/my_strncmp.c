/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** my_strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i;

    for (i = 0; s1[i] != '\0' && s2[i] != 0 && i < n; i++) {
        if (s1[i] < s2[i] && s1[i] != s2[i])
            return (-1);
        if (s1[i] > s2[i] && s1[i] != s2[i])
            return (1);
    }
    return (0);
}
