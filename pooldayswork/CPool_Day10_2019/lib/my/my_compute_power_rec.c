/*
** EPITECH PROJECT, 2019
** my_compute_power_rec
** File description:
** compute param power
*/

int my_pow(int nb, int p)
{
    if (p == 0)
        return 1;
    else if (p < 0)
        return 0;
    else
        return nb * my_pow(nb, --p);
}
