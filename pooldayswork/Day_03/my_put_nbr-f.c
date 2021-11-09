/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** print number with my_putchar
*/

long my_pow(long a, long turns)
{
    if (turns == 0)
    {
        return 1;
    }
    else
    {
        return a * my_pow(a, --turns);
    }
}


        
long print_nb(long nb, long turns)
{
    int check = 
    int display_nb = (nb / my_pow(10, turns) % 10) + '0';
    if (display_nb - '0' == 0)
    {
        return 0;
    }
    turns++;
    print_nb(nb, turns);
    my_putchar(display_nb);
    return 0;
}
    
int my_put_nbr(int nb)
{
    int turns = 0;
    if (nb < 0)
    {
        my_putchar('-');
        nb = -nb;
    }
    print_nb(nb, turns);
}
       
