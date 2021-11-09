/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** Day07 task02
*/

void my_putchar(char c);

int strle(char const *dest)
{
    int i = 0;

    while (dest[i] != '\0')
        i++;
    return i;
}

char *my_strcat(char *dest, char const *src)
{
    int dest_l = strle(dest);
    int i;

    for (i = 0; src[i] != '\0'; i++) {
        dest[dest_l + i] = src[i];
    }
    dest[dest_l + i] = '\0';
    return dest;
}
