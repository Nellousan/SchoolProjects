/*
** EPITECH PROJECT, 2019
** my_print_comb2
** File description:
** print osef
*/

int char_to_number(char digit_1, char digit_2)
{
    int number = ((digit_1 - '0') * 10) + (digit_2 - '0');
    return number;
}

int print_digits2(char digit_1, char digit_2, char digit_3, char digit_4)
{
    my_putchar(digit_1);
    my_putchar(digit_2);
    my_putchar(' ');
    my_putchar(digit_3);
    my_putchar(digit_4);
    
}

int conditions2(char digit_1, char digit_2, char digit_3, char digit_4)
{
    int number_1 = char_to_number(digit_1, digit_2);
    int number_2 = char_to_number(digit_3, digit_4);
    if (number_1 < number_2)
    {
        print_digits2(digit_1, digit_2, digit_3, digit_4);
        if (digit_1 == '9' && digit_2 == '8' && digit_3 == '9' && digit_4 == '9')
        {
            return 0;
        }
        else if (number_1 <= 98 && number_2 <= 99)
        {
            my_putchar(',');
            my_putchar(' ');
        }
    }
}

int increment2(digit_1, digit_2, digit_3, digit_4)
{
    int i = 0;
    for (i = 0; i < 10000; i++)
    {
        conditions2(digit_1, digit_2, digit_3, digit_4);
        if (digit_2 == '9' && digit_3 == '9' && digit_4 == '9')
        {
            digit_2 = '0';
            digit_3 = '0';
            digit_4 = '0';
            digit_1++;
        }
        else if (digit_3 == '9' && digit_4 == '9')
        {
            digit_3 = '0';
            digit_4 = '0';
            digit_2++;
        }
        else if (digit_4 == '9')
        {
            digit_4 = '0';
            digit_3++;
        }
        else
        {
            digit_4++;
        }
    }
}
int my_print_comb2(void)
{
    char digit_1 = '0';
    char digit_2 = '0';
    char digit_3 = '0';
    char digit_4 = '0';
    increment2(digit_1, digit_2, digit_3, digit_4);
}
