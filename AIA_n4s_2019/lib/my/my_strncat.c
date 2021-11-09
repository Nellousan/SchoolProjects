/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** Day07 task03
*/

void my_putchar(char c);

int strlenmy(char const *dest)
{
    int i = 0;

    while (dest[i] != '\0')
        i++;
    return i;
}

char *my_strncat(char *dest, char const *src, int n)
{
    int i;
    int dest_l = strlenmy(dest);

    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[dest_l + i] = src[i];
    }
    dest[dest_l + i] = '\0';
    return dest;
}
