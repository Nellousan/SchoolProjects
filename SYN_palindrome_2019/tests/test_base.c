/*
** EPITECH PROJECT, 2020
** base test
** File description:
** criterion
*/

#include <criterion/criterion.h>
#include "palindrome.h"
#include "my.h"

Test(base_convert, string_to_int_1)
{
    int nb1 = convert_base_int("1010", 2);
    cr_assert_eq(nb1, 10);
}

Test(base_convert, string_to_int_2)
{
    int nb1 = convert_base_int("20", 5);
    cr_assert_eq(nb1, 10);
}

Test(base_convert, string_to_int_3)
{
    int nb1 = convert_base_int("15", 6);
    cr_assert_eq(nb1, 11);
}

Test(base_convert, string_to_int_4)
{
    int nb1 = convert_base_int("11001", 2);
    cr_assert_eq(nb1, 25);
}

Test(base_convert, string_to_int_5)
{
    int nb1 = convert_base_int("01", 9);
    cr_assert_eq(nb1, 1);
}

Test(base_convert, string_to_int_6)
{
    int nb1 = convert_base_int("0012", 3);
    cr_assert_eq(nb1, 5);
}

Test(base_convert, int_to_string_1)
{
    char *str = convert_base_str(10, 2);
    cr_assert_str_eq(str, "1010");
}

Test(base_convert, int_to_string_2)
{
    char *str = convert_base_str(10, 5);
    cr_assert_str_eq(str, "20");
}

Test(base_convert, int_to_string_3)
{
    char *str = convert_base_str(43, 10);
    cr_assert_str_eq(str, "43");
}

Test(base_convert, int_to_string_4)
{
    char *str = convert_base_str(10, 3);
    cr_assert_str_eq(str, "101");
}
