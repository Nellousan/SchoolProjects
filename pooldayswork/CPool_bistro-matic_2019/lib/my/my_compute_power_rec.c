/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** my_compute_power_rec
*/

int my_compute_power_rec(int nb, int p)
{
    int v = 1;

    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    if (p > 0) {
        v = nb * my_compute_power_rec(nb, p - 1);
    }
    return (v);
}
