/*
** EPITECH PROJECT, 2020
** palindrome
** File description:
** c
*/

#include "palindrome.h"
#include "my.h"
#include "a_malloc.h"

int main(int argc, char **argv)
{
    pal_t *pal = get_opts(argc, argv);
    if (argc > 1 && !my_strcmp(argv[1], "-h")) {
        display_help();
        return 84;
    }
    if (!pal || !arg_validity(pal)) {
        my_printf("invalid argument\n");
        a_malloc(A_MALLOC_FREE | A_LIST(1));
        return 84;
    }
    if (SNB)
        iterate_nb(pal, NB);
    else if (SPAL)
        iterate_pal(pal);
    a_malloc(A_MALLOC_FREE | A_LIST(0));
    a_malloc(A_MALLOC_FREE | A_LIST(1));
    return 0;
}
