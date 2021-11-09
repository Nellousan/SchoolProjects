/*
** EPITECH PROJECT, 2019
** my_compute_factorial_it
** File description:
** Compute !param
*/

int my_compute_factorial_rec(int nb)
{
    if (nb == 0)
        return 1;
    else if (nb >= 1 && nb < 13)
        return nb * my_compute_factorial_rec(nb - 1);
    return 0;
}
