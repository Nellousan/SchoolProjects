/*
** EPITECH PROJECT, 2020
** misc2
** File description:
** a
*/

int is_alphanum(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] < 'a' || str[i] > 'z') &&
        (str[i] < 'A' || str[i] > 'Z') && str[i] != '_')
            return 0;
    return 1;
}
