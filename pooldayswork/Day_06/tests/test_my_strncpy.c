/*
** EPITECH PROJECT, 2019
** test my_strncpy
** File description:
** explicit name
*/

#include <criterion/criterion.h>

Test(my_strncpy, copy_five_characters_in_empty_array)
{
    chart des[6] = {0};

    my_strncpy(dest, "HelloWorld", 5);
    cr_assert_str_eq(dest, "Hello");
}
