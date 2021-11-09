/*
** EPITECH PROJECT, 2019
** my_compute_power_it
** File description:
** compute param power
*/

int my_compute_power_it(int nb, int p)
{
    int nb2 = 1;
    if (p == 0)
        return 1;
    else if (p < 0)
        return 0;
    for (int i = 0; i != p; i++)
        nb2 = nb2 * nb;
    return nb2;
}
