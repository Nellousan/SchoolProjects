/*
** EPITECH PROJECT, 2019
** my_isneg
** File description:
** return positive or negative
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n >= 0)
    {
        my_putchar('P');
    }
    else
    {
        my_putchar('N');
    }
}
