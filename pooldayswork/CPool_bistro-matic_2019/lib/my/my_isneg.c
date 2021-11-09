/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** my_isneg
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    if (n >= 0)
        my_putchar('P');
    my_putchar('\n');
    return (0);
}
