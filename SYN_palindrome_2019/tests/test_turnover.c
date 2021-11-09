/*
** EPITECH PROJECT, 2020
** ll
** File description:
** ll
*/

#include <criterion/criterion.h>
#include "palindrome.h"

Test(turnover, turnover_1)
{
    pal_t *pal = init_pal();
    int nb = turnover(pal, 21);
    cr_assert_eq(nb, 33);
}

Test(turnover, turnover_2)
{
    pal_t *pal = init_pal();
    int nb = 0;
    BASE = 2;
    nb = turnover(pal, 6);
    cr_assert_eq(nb, 9);
}

Test(turnover, turnover_3)
{
    pal_t *pal = init_pal();
    int nb = 0;
    BASE = 5;
    nb = turnover(pal, 5);
    cr_assert_eq(nb, 6);
}

Test(turnover, turnover_4)
{
    pal_t *pal = init_pal();
    int nb = 0;
    BASE = 2;
    nb = turnover(pal, 10);
    cr_assert_eq(nb, 15);
}
