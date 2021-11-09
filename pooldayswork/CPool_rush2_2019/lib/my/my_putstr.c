/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** affiche une chaine de caractères
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int i  = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return 0;
}
