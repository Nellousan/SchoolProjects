/*
** EPITECH PROJECT, 2020
** syntax_check
** File description:
** checking arg validity
*/

#include "my.h"
#include "fractals.h"

int get_occurences(char const *str, char c)
{
    int occ = 0;

    for (int i = 0; str[i] != '\0'; i++)
        occ += (str[i] == c) ? 1 : 0;
    return occ;
}

int syntax_check(int argc, char **argv)
{
    char *str = "Chain1 and Chain2 myst have the same number of line breaks";

    if (argc < 4) {
        my_putstr_error("Too few arguments: 3 is required\n");
        return 0;
    }
    if (!my_str_isnum(argv[1])) {
        my_putstr_error("First argument must be a positive number\n");
        return 0;
    }
    if (get_occurences(argv[2], '@') != get_occurences(argv[3], '@')) {
        my_putstr_error(str);
        return 0;
    }
    return 1;
}
