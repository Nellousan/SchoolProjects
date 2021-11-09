/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** my_put_nbr
*/

void my_putchar(char c);

void my_put_nbr_pos(int nb)
{
    int a = 1;

    while ((nb / a) > 9) {
        a = a * 10;
    }
    while (a != 0) {
        my_putchar('0' + (nb / a) % 10);
        a = a / 10;
    }
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    my_put_nbr_pos(nb);
    return 0;
}
