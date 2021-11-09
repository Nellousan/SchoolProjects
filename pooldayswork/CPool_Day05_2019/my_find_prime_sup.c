/*
** EPITECH PROJECT, 2019
** my_is_prime_sup
** File description:
** return the next prime number after the given one
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    if (nb <= 2)
        return 2;
    int check = 0;
    if (nb == 2147483647)
        return 0;
    while (1)
    {
        check = my_is_prime(nb + 1);
        if (check == 1)
            return nb + 1;
        nb++;
    }
}
