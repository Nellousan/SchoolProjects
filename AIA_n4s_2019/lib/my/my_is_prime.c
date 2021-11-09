/*
** EPITECH PROJECT, 2019
** my_is_prime
** File description:
** Day05 task06
*/

int my_is_prime(int nb)
{
    int j = 0;

    for (int i = 2; i < nb / 2; i++) {
        j = nb / i;
        if (i * j == nb)
            return 0;
    }
    return 1;
}
