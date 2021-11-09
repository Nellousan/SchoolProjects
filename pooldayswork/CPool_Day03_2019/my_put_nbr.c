
int my_put_nbr(int nb)
{
    if (nb == -2147483648)
    {
        my_putchar('-');
        my_putchar('2');
        my_putchar('1');
        my_putchar('4');
        my_putchar('7');
        my_putchar('4');
        my_putchar('8');
        my_putchar('3');
        my_putchar('6');
        my_putchar('4');
        my_putchar('8');
        return 0;
    }
    else if (nb < 0)
    {
        nb = -nb;
        my_putchar('-');
    }

    int a = nb % 10 + '0';
    nb = nb / 10;
    if (nb > 0)
        my_put_nbr(nb);
    my_putchar(a);
    return (0);
}   
