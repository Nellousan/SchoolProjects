/*
** EPITECH PROJECT, 2019
** printf
** File description:
** my_put_long_long
*/

void my_putchar(char c);

void my_put_long_long_pos(long long int nb)
{
    long long int a = 1;

    while ((nb / a) > 9) {
        a = a * 10;
    }
    while (a != 0) {
        my_putchar('0' + (nb / a) % 10);
        a = a / 10;
    }
}

int my_put_long_long(long long int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    my_put_long_long_pos(nb);
    return 0;
}
