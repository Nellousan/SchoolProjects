/*
** EPITECH PROJECT, 2020
** dad
** File description:
** da
*/

#include "palindrome.h"
#include "my.h"
#include "a_malloc.h"

int turnover(pal_t *pal, int nb)
{
    char *cnb = convert_base_str(nb, BASE);
    reverse(cnb);
    return nb + convert_base_int(cnb, BASE);
}

bool is_palindrome(pal_t *pal, int nb)
{
    char *p1 = convert_base_str(nb, BASE);
    int nblen = my_strlen(p1);
    char *p2 = my_strdup(p1 + nblen / 2 + nblen % 2);
    if (my_strlen(p1) == 1)
        return true;
    p1[nblen / 2] = '\0';
    reverse(p2);
    if (!my_strcmp(p1, p2))
        return true;
    return false;
}

void iterate_nb(pal_t *pal, int nb)
{
    int i = 0;
    int cnb = nb;
    for (i = 0; i < IMAX; i++) {
        if (is_palindrome(pal, cnb) && i >= IMIN)
            break;
        cnb = turnover(pal, cnb);
        a_malloc(A_MALLOC_FREE);
    }
    if (is_palindrome(pal, cnb) && i >= IMIN)
        my_printf("%d leads to %d in %d iteration(s) in base %d\n",
        nb, cnb, i, BASE);
    else
        my_printf("no solution\n");
    return;
}

void iterate_pal(pal_t *pal)
{
    bool found = false;
    int i = 0;
    int cnb = 0;
    int iteration = PAL;
    for (int j = 0; j <= iteration; j++) {
        cnb = j;
        for (i = 0; cnb != PAL && i < IMAX; i++) {
            cnb = turnover(pal, cnb);
            a_malloc(A_MALLOC_FREE);
        }
        if (cnb == PAL && i >= IMIN) {
            my_printf("%d leads to %d in %d iteration(s) in base %d\n",
            j, PAL, i, BASE);
            found = true;
        }
    } if (!found)
        my_printf("no solution\n");
    return;
}
