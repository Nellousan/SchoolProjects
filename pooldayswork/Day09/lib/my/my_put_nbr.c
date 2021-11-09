/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** print number
*/

void my_putchar(char c);
int my_putstr(char const *str);

int my_putnbr(int nb)
{
    if (nb == -2147483648) {
        my_putstr("-2147483648");
        return 0;
    }
    else if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    int a = nb % 10 + '0';
    nb = nb / 10;
    if (nb > 0)
        my_putnbr(nb);
    my_putchar(a);
    return (0);
}
