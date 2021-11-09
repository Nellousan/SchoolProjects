/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** get first number of a string
*/

int my_strlen(char const *str);

int my_pow(int a, int turns)
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
       
int check_integer(long nb)
{
    int nb2 = 0;
    if (nb < -2147483648 || nb > 2147483647)
        return nb2;
    else
    {
        nb2 = nb;
        return nb2;
    }
}

int char_to_int(char *str, int neg)
{
    long nb = 0;
    int i = 0;
    int str_length = my_strlen(str);
    while (str_length != 0)
    {
        nb += (str[i] - '0') * my_pow(10, str_length - 1);
        str_length--;
        i++;
    }
    if (neg == 1)
        nb = -nb;
    return check_integer(nb);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int i2 = 0;
    int neg = 0;
    char fill_char[20] = "";
    int found_number_trigger = 0;
    int negative_check_trigger = 0;
    int str_length = my_strlen(str);
    int no_break = str_length + 1;
    my_putstr("l: ");
    my_putchar(str_length + '0');
    my_putchar('\n');
    while (i < 10)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            if (negative_check_trigger == 0 && str[i - 1] == '-')
            {
                my_putstr("\n negative");
                negative_check_trigger = 1;
                neg = 1;
            }
            fill_char[i2] = str[i];
            my_putstr(str[i]);
            my_putstr("; ");
            found_number_trigger = 1;
            i2++;
            
        }
        if (found_number_trigger == 1 && str[i] < '0')
        {
            my_putstr("\nbreak");
            break;
        }
        if (found_number_trigger == 1 && str[i] > '9')
        {
            my_putstr("\nbreak");
            break;
        }
        i++;        
    }
    my_putstr("\nreturn");
    return char_to_int(fill_char, neg);
}
