/*
** EPITECH PROJECT, 2019
** my_print_comb
** File description:
** print osef
*/

int conditions(char digit_1, char digit_2, char digit_3);

int print_digits(char digit_1, char digit_2, char digit_3)
{
    my_putchar(digit_1);
    my_putchar(digit_2);
    my_putchar(digit_3);
}

int increment (char digit_1, char digit_2, char digit_3)
{
    int i = 0;
    for (i = 0; i < 1000; i++)
    {
        conditions(digit_1, digit_2, digit_3);
        if (digit_2 == '9')
        {
            digit_2 = '0';
            digit_1++;
        }
        else if (digit_3 == '9')
        {
            digit_3 = '0';
            digit_2++;
        }
        digit_3++;
    }
}

int conditions(char digit_1, char digit_2, char digit_3)
{
    if (digit_1 < digit_2 && digit_2 < digit_3 && digit_1 != digit_2 && digit_2 != digit_3 && digit_1 != digit_3)
    {
        print_digits(digit_1, digit_2, digit_3);
        if (digit_1 == '7' && digit_2 == '8' && digit_3 == '9')
        {
            return 0;
        }
        else if (digit_1 <= '7' && digit_2 <= '8' && digit_3 <= '9')
        {
            my_putchar(',');
            my_putchar(' ');
        }
    }
}        


int my_print_comb(void)
{
    char digit_1 = '0';
    char digit_2 = '0';
    char digit_3 = '0';;
    increment(digit_1, digit_2, digit_3);
}
