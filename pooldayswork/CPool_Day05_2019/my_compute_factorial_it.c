/*
** EPITECH PROJECT, 2019
** my_compute_factorial_it
** File description:
** compute !nb
*/

int my_compute_factorial_it(int nb)
{
    if (nb == 0)
        return 1;
    else if (nb < 0 || nb > 12)
        return 0;
    for (int i = nb - 1; i > 1; --i)
        nb = nb * i;
    return nb;
}
