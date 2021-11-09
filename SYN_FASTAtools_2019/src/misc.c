/*
** EPITECH PROJECT, 2020
** misc
** File description:
** c
*/

#include "fasta.h"
#include "my.h"

bool is_dna(char c)
{
    if (c == 'A' || c == 'a' || c == 'T' || c == 't' || c == 'G' ||
    c == 'g' || c == 'C' || c == 'c' || c == 'N' || c == 'n')
        return true;
    return false;
}

static bool is_lowalpha(char c)
{
    if (c >= 'a' && c <= 'z')
        return true;
    return false;
}

void to_uppercase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (is_lowalpha(str[i]))
            str[i] -= 32;
    return;
}

int my_atoi(char *str)
{
    int neg = 0;
    int nb = 0;
    if (str[0] == '-') {
        str++;
        neg = 1;
    }
    for (int i = 0; str[i] != '\0'; i++)
        nb += (str[i] - '0') * my_pow(10, my_strlen(str) - (i + 1));
    if (neg) {
        nb = -nb;
        str--;
    }
    return nb;
}

void reverse(char *str)
{
    char *cstr = my_strdup(str);
    int len = my_strlen(str);
    int ilen = len - 1;
    int i = 0;
    for (; i < len; i++, ilen--)
        str[i] = cstr[ilen];
    return;
}
