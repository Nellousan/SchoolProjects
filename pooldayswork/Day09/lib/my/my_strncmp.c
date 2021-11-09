/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** return 1 if s1 is different and/or longer,
** 0 if same, -1 if shorter for n characters
*/

int my_strlen(char const *str);

int my_strncmp(char const *s1, char const *s2, int n)
{
    int nb = 0;
    if (n > my_strlen(s1) || n > my_strlen(s2))
        return 0;
    else if (n < 0)
        return -87;
    for (int i = 0; i < n; i++)
        if (s1[i] != s2[i]) {
            nb = s1[i] - s2[i];
            return nb;
        }
    return 0;
}
