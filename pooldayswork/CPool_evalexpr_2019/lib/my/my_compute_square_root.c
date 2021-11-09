/*
** EPITECH PROJECT, 2019
** my_compute_squar_root
** File description:
** compute square root
*/

int my_compute_power_rec(int nb, int p);

int my_sqrt(int nb)
{
    if (nb <= 0)
        return 0;
    for (int i = 0; i <= 46340; i++) {
        if (i * i == nb)
            return i;
    }
    return 0;
}
