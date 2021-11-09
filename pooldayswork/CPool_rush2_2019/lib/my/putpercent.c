/*
** EPITECH PROJECT, 2019
** putpercent
** File description:
** display percent
*/

void my_putchar(char c);

int my_putstr(char const *str);

int my_putpercent(int nb)
{
    if (nb >= 10000) {
        my_putstr("100.00");
        return 1;
    }
    char str[6] = "00000";
    int i = 4;
    for (i; i >= 3; i--) {
        str[i] = nb % 10 + '0';
        nb /= 10;
    }
    str[i] = '.';
    i--;
    for (i; i >= 0; i--) {
        str[i] = nb % 10 + '0';
        nb /= 10;
    }
    my_putstr(str);
}
