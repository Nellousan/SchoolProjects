/*
** EPITECH PROJECT, 2019
** my_swap
** File description:
** swap two integers
*/

void my_swap(int *a, int *b)
{
    int c = 0;
    c = *b;
    *b = *a;
    *a = c;    
}
