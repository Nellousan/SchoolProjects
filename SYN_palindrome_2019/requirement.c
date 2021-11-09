/*
** EPITECH PROJECT, 2020
** req
** File description:
** a
*/

int my_factrec_synthesis(int nb)
{
    if (nb >= 1 && nb < 13)
        return nb * my_factrec_synthesis(nb - 1);
    else if (nb == 0)
        return 1;
    else
        return 0;
}

int my_squareroot_synthesis(int nb)
{
    for (int i = 0; i <= 46340; i++) {
        if (i * i == nb)
            return i;
    }
    return -1;
}
