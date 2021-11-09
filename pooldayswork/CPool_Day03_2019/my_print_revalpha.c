/*
** EPITECH PROJECT, 2019
** my_print_revalpha
** File description:
** print alphabet in reverse
*/


int my_print_revalpha(void)
{
    int i = 0;
    for (i = 122; i != 96; i--){
        my_putchar(i);
    }
    return 0;
}

