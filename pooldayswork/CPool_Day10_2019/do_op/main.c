/*
** EPITECH PROJECT, 2019
** main do-op
** File description:
** 
*/

#include <stddef.h>

struct operator
{
    char symbol;
    int (*fptr)(int, int);
};

int my_add(int a, int b);
int my_sub(int a, int b);
int my_div(int a, int b);
int my_mul(int a, int b);
int my_mod(int a, int b);
int my_putnbr(int nb);
int my_strlen(char *str);
int my_pow(int nb, int p);
int my_putstr(char *str);

int isnum(char c)
{
    if (c < '0' || c > '9')
        return 0;
    return 1;
}

char *cut_num(char *str)
{
    int neg = 0;
    size_t k = 0;
    size_t i = 0;
    for (i; str[i] == '-'; i++) {
        k++;
        neg = 1;
    }
    for (i; isnum(str[i]); i++);
    str[i] = '\0';
    return str + k - neg;
}

int my_strtoint(char *str)
{
    int neg = 0;
    int buffer = 0;
    size_t length = my_strlen(str) - 1;
    size_t i = 0;
    if (str[0] == '-') {
        i++;
        length--;
        neg = 1;
    }
    for (i; str[i] != '\0'; i++) {
        buffer += (str[i] - '0') * my_pow(10, length);
        length--;
    }
    if (neg)
        return -buffer;
    return buffer;
}

int main(int argc, char **argv)
{
    const struct operator operations_fc[] = {
        {'+', &my_add}, {'-', &my_sub}, {'/', &my_div},
        {'*', &my_mul}, {'%', &my_mod}, {'\0', NULL}};
    if (argc < 4)
        return 0;
    int operand1 = my_strtoint(cut_num(argv[1]));
    int operand2 = my_strtoint(cut_num(argv[3]));
    for (size_t i = 0; operations_fc[i].symbol != '\0'; i++) {
        if (argv[2][0] == '/' && operand2 == 0) {
            my_putstr("Stop: division by zero\n");
            return 0;
        } else if (argv[2][0] == '%' && operand2 == 0) {
            my_putstr("Stop: modulo by zero\n");
            return 0;
        } else if (operations_fc[i].symbol == argv[2][0]) {
            my_putnbr(operations_fc[i].fptr(operand1, operand2));
            return 0;
        }
    }
    my_putnbr(0);
    return 84;
}
