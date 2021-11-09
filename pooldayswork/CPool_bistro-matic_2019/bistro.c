/*
** EPITECH PROJECT, 2019
** bistromatic
** File description:
** calculations
*/

#include "new.h"
#include "my.h"
#include "bistro.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

char *infix_postfix(char *str, char **argv)
{
    int j = 0;
    stack_t *stack = NULL;
    char *output = malloc(sizeof(char) * my_strlen(str) * 2 + 1);

    for (int i = 0; str[i] != '\0'; i++) {
        isop(str[i], argv) == 1 ? output[j] = str[i], j++ : 0;
        if (priority(peek(stack), argv) > priority(str[i], argv) && isop(str[i], argv) == 2) {
            output[j++] = peek(stack);
            pop(&stack);
        } (isop(str[i], argv) == 2) ? output[j++] = ' ', push(&stack, str[i]) : 0;
        (str[i] == argv[2][0]) ? push(&stack, str[i]) : 0;
        if (str[i] == argv[2][1]){
            while (peek(stack) != argv[2][0])
                output[j++] = pop(&stack);
            (peek(stack) == argv[2][0]) ? pop(&stack) : 0;
        } if (str[i+1] == '\0' && is_empty(stack) == false)
            while (is_empty(stack) == false)
                output[j++] = pop(&stack);
        output[j] = '\0';
    } return output;
}

char *optodo(int i, char *output, char *nb1, char *nb2, char **argv)
{
    char *output2 = malloc(sizeof(char) * my_strlen(output) * 2 + 1);

    nb1 = convert_base(nb1, argv[1], "0123456789", argv[2]);
    nb2 = convert_base(nb2, argv[1], "0123456789", argv[2]);

    if (output[i] == argv[2][2])
        output2 = send_add(nb1, nb2);
    if (output[i] == argv[2][3])
        output2 = send_sub(nb1, nb2);
    else if (output[i] == argv[2][5])
        output2 = send_div(nb1, nb2, 0);
    else if (output[i] == argv[2][6])
        output2 = send_div(nb1, nb2 ,1);
    output2 = convert_base(output2, "0123456789", argv[1], argv[2]);
    return output2;
}

char *beforeoptodo(char *output, int k, int a, int i, char **argv)
{
    char *nb1 = malloc(sizeof(char) * my_strlen(output) + 1);
    char *nb2 = malloc(sizeof(char) * my_strlen(output) + 1);
    char *output2 = malloc(sizeof(char) * my_strlen(output) * 2 + 1);

    for (; output[k] != ' '; k++, a++)
        nb1[a] = output[k];
    nb1[a] = '\0';
    a = 0;
    k++;
    (isop(output[k], argv) == 2) ? k++, nb2[a] = argv[2][3], a++ : 0;
    for (;isop(output[k], argv) != 2; k++, a++)
        nb2[a] = output[k];
    nb2[a] = '\0';
    output2 = optodo(i, output, nb1, nb2, argv);
    return output2;
}

char*calculate(char *output, char **argv)
{
    int a = 0;
    int i = 0;
    int k = 0;
    int posfirstspace = 0;
    int twospace = 0;
    char *output1 = malloc(sizeof(char) * my_strlen(output) * 2 + 1);
    char *output2 = malloc(sizeof(char) * my_strlen(output) * 2 + 1);
    char *output3 = malloc(sizeof(char) * my_strlen(output) * 2 + 1);
    int iout = 0;
    int iout1 = 0;

    for (; output[i] != '\0'; i++)
        if (isop(output[i], argv) == 2 && isop(output[i+1], argv) != 1) {
            k = i;
            break;
        }
    for (; twospace != 2; k--) {
        (output[k] == ' ' || k <= 0) ? twospace++ : 0;
        (twospace == 1 && posfirstspace == 0) ? posfirstspace = k : 0;
    }
    for (k++; iout1 != k + 1; iout1++)
        output1[iout1] = output[iout1];
    output1[iout1] = '\0';
    for (int iout2 = k; iout2 != i + 1; iout2++)
        output2[iout2 - k - 1] = output[iout2];
    for (int iout3 = i; output[iout3] != '\0'; iout3++)
        output3[iout3 - i - 1] = output[iout3];
    (output[k] == ' ') ? k++ : 0;
    output2 = beforeoptodo(output, k, a, i, argv);
    for (int iout1 = 0; output1[iout1] != '\0'; iout1++, iout++);
    (iout-1 == 0) ? iout = 0 : 0;
    for (int iout2 = 0; output2[iout2] != '\0'; iout2++, iout++)
        output[iout] = output2[iout2];
    for (int iout3 = 0; output3[iout3] != '\0'; iout3++, iout++)
        output[iout] = output3[iout3];
    output[iout] = '\0';
    return output;
}

char *disp_result(char **argv, char *expr)
{
    int nboperator = 0;
    int i = 0;
    char *output = infix_postfix(expr, argv);
    char *result = malloc(sizeof(char) * my_strlen(output) * 2 + 1);

    result = calculate(output, argv);
    for (; output[i] != '\0'; i++)
        if (isop(output[i], argv) == 2 && (isop(output[i+1], argv) != 1))
            nboperator++;
    for (; nboperator != 0; nboperator--) {
        result = calculate(output, argv);
        output = result;
    }
    my_putstr(result);
    return result;
}
