/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main o cat params
*/

#include <stdlib.h>

int cat_params(char **argv);
int cat_pipe(void);

int main(int argc, char **argv)
{
    if (argc < 2) {
        cat_pipe();
        return 0;
    }
    cat_params(argv);
}
