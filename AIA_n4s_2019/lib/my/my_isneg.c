/*
** EPITECH PROJECT, 2019
** my_isneg
** File description:
** negative
*/

void my_putchar(char c);

int my_isneg(int nb)
{
    if (nb < 0) {
        my_putchar('N');
    }
    else {
        my_putchar('P');
    }
    return (0);
}
