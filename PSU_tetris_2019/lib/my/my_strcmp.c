/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** return 1 if s1 is different and/or longer, 0 if same, -1 if shorter
*/

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] > s2[i])
            return 1;
        if (s1[i] < s2[i])
            return -1;
    }
    if (s2[i] == '\0' && s1[i] != '\0')
        return 1;
    if (s1[i] == '\0' && s2[i] != '\0')
        return -1;
    return 0;
}
