/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** my_find_prime_sup
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int test = my_is_prime(nb);

    if (nb > 2147483647 || nb < -2147483647)
        return 0;
    while (test != 1) {
        nb++;
        test = my_is_prime(nb);
    }
    return (nb);
}
