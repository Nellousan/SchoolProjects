/*
** EPITECH PROJECT, 2019
** special cases
** File description:
** 
*/

int line_case(char *map)
{
    for (int i = 0; map[i] != '\0'; i++)
        if (map[i] == '.') {
            map[i] = 'x';
            return 1;
        }
    return 0;
}
