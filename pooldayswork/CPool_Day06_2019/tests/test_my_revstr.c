/*
** EPITECH PROJECT, 2019
** test my_revstr
** File description:
** explicit name
*/

#include <criterion/criterion.h>

Test(my_revstr, reverse_string)
{
    char dest[] = "HelloWorld";
    my_revstr(dest);
    cr_assert_str_eq(dest, "dlroWolleH");
}

