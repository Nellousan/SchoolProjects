/*
** EPITECH PROJECT, 2019
** get_corners
** File description:
** get_corners
*/

char sec_corn(char *buffer)
{
    int i = 0;
    while (buffer[i] != '\n')
        i++;
    return buffer[i - 1];
}

char frth_corn(char *buffer)
{
    int i = 0;
    while (buffer[i] != '\0')
        i++;
    return buffer[i - 2];
}
