/*
** EPITECH PROJECT, 2019
** tes_my_put_nbr
** File description:
** test my_put_nbr.c
*/

int main()
{
    my_put_nbr(0);
    my_putchar('\n');
    my_put_nbr(42);
    my_putchar('\n');
    my_put_nbr(601);
    my_putchar('\n');
    my_put_nbr(-5);
    my_putchar('\n');
    my_put_nbr(-2147483648);
    my_putchar('\n');
    my_put_nbr(2147483647);
}
