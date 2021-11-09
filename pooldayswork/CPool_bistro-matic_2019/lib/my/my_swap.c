/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** my_swap
*/

void my_swap(int *a, int *b)
{
    int z;

    z = *a;
    *a = *b;
    *b = z;
}
