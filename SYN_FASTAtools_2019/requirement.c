/*
** EPITECH PROJECT, 2020
** requiremetn
** File description:
** d
*/

#include <stdbool.h>

static bool is_lowalpha(char c)
{
    if (c >= 'a' && c <= 'z')
        return true;
    return false;
}

static bool is_alphanum(char c)
{
    if ((c >= 'a' && c <= 'z') ||
    (c >= 'A' && c <= 'Z') ||
    (c >= '0' && c <= '9'))
        return true;
    return false;
}

char *my_strcapitalize_synthesis(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((is_lowalpha(str[i]) && i == 0) ||
        (is_lowalpha(str[i]) && !is_alphanum(str[i - 1])))
            str[i] -= 32;
    }
    return str;
}
