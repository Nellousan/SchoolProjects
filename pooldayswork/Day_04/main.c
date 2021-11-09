/*
** EPITECH PROJECT, 2019
** main.c test
** File description:
** test pool
*/

#include <stdio.h>


int my_strlen(char const *str);
int my_putstr(char const *str);
char *my_evil_str(char *str);
void my_putchar(char c);
int my_getnbr(char const *str);

int main(void)
{
    char str[20] = "hello test";
    my_putstr(str);

    printf("\ntest my_strlen: %i\n", my_strlen(str));
    
    my_evil_str(str);
    my_putstr(str);
    my_putchar('\n');
    my_putstr("\ntest my_getnbr with adg456684fr: ");
    int getnbr = my_getnbr("adg456684fr");
    printf("%i", getnbr);
    //my_putstr("\ntest my_getnbr with abcdegegah: ");
    //int getnbr = my_getnbr("abcdegegah53173291");
    //printf("%i", getnbr);
}
