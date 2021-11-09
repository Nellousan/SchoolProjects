/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** Day06 task02
*/

void my_putchar(char c);

int my_strl(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n) {
        dest[i] = src[i];
        i++;
        if (i > my_strl(dest))
            dest[i++] = '\0';
    }
    return (dest);
}
