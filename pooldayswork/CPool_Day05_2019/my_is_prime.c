/*
** EPITECH PROJECT, 2019
** my_is_prime
** File description:
** check if number is prime
*/

int my_compute_square_root(int nb);

int approx_sqrt(int nb)
{
    if (nb <= 0)
        return 0;
    for (int i = 0; i <= 46340; i++)
    {
        if (i * i >= nb)
            return i + 1;
    }
    return 0;
}

int my_is_prime(int nb)
{
    if (nb <= 0 || nb == 1)
        return 0;
    if (nb == 2)
        return 1;
    for(int i = 2; i < approx_sqrt(nb); i++)
        if(nb % i == 0)
            return 0;
    return 1;
}
