/*
** EPITECH PROJECT, 2019
** my_compute_square_root
** File description:
** Day05 task05
*/

int my_compute_square_root(int nb)
{
    for (int i = 0; i < nb/2; i++) {
        if (i * i == nb)
            return 1;
    }
    return 0;
}
