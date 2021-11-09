/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** my_is_prime
*/

int particular_case(int nb)
{
    if (nb < 0)
        nb = -nb;
    if (nb == 0 || nb == 1)
        return 0;
    return 0;
}

int my_is_prime(int nb)
{
    particular_case(nb);
    if (nb % 2 == 0) {
        if (nb == 2)
            return (1);
        return (0);
    }
    for (int i = 2; i < nb; i++)
        if (nb % i == 0)
            return (0);
    return (1);
}
