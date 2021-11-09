/*
** EPITECH PROJECT, 2020
** get_opts
** File description:
** c
*/

#include "palindrome.h"
#include "a_malloc.h"
#include "my.h"

static bool check_opts(char *str, char *av, pal_t *pal)
{
    if (!my_strcmp(str, "-n")) {
        NB = my_atoi(av);
        SNB = my_astrdup(av, 1);
        return true;
    } if (!my_strcmp(str, "-p")) {
        PAL = my_atoi(av);
        SPAL = my_astrdup(av, 1);
        return true;
    } if (!my_strcmp(str, "-b")) {
        BASE = my_atoi(av);
        return true;
    } if (!my_strcmp(str, "-imax")) {
        IMAX = my_atoi(av);
        return true;
    } if (!my_strcmp(str, "-imin")) {
        IMIN = my_atoi(av);
        return true;
    }
    return false;
}

pal_t *init_pal(void)
{
    pal_t *pal = a_malloc(sizeof(pal_t) | A_LIST(1));
    NB = 0;
    SNB = NULL;
    PAL = 0;
    SPAL = NULL;
    IMIN = 0;
    IMAX = 100;
    BASE = 10;
    return pal;
}

static bool is_valid_number(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return false;
    return true;
}

bool arg_validity(pal_t *pal)
{
    if (SPAL && SNB)
        return false;
    if (IMAX < IMIN)
        return false;
    if (IMAX < 0 || IMIN < 0)
        return false;
    if ((NB < 0 && SNB) || (PAL < 0 && SPAL))
        return false;
    if (BASE > 10 || BASE < 1)
        return false;
    if (!is_palindrome(pal, PAL) && SPAL)
        return false;
    if (!SNB && !SPAL)
        return false;
    return true;
}

pal_t *get_opts(int argc, char **argv)
{
    pal_t *pal = init_pal();
    if (argc % 2 == 0 || argc <= 1)
        return NULL;
    for (int i = 1; i < argc; i = i + 2) {
        if (!is_valid_number(argv[i + 1]) ||
        !check_opts(argv[i], argv[i + 1], pal))
            return NULL;
    }
    return pal;
}
