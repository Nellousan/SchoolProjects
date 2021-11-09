/*
** EPITECH PROJECT, 2019
** test_cat
** File description:
** test cat
*/

#include <criterion/criterion.h>
//int cat_params(**argv);

Test(cat_params, concatenate_params)
{
    char *file_path[] = {"test", "test", NULL};
    int res = cat_params(file_path);
    cr_assert_eq(res, 0);
}

