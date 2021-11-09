/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** copy n str char into other str
*/

int my_strlen(char const *str);
int my_putnbr(int nb);

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
        dest[i] = src[i];
    if (n > my_strlen(src))
        dest[i + 1] = '\0';
    return dest;
}
