/*
** EPITECH PROJECT, 2019
** tests
** File description:
** 
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(sum_stdarg, test_with_i_0)
{
    int sum = sum_stdarg(0, 5, 2, 7, 8, -5, 20);
    cr_assert_eq(sum, 32);
}

Test(sum_stdarg, test_with_i_1)
{
    int sum = sum_stdarg(1, 3, "hello", "pleb", "folks");
    cr_assert_eq(sum, 14);
}

Test(disp_stdarg, aaa, .init=redirect_all_stdout)
{
    disp_stdarg("iiscs", 80, 30, "hello", 'g', "world");
    cr_expect_stdout_eq_str("80\n30\nhello\ng\nworld\n");
}
