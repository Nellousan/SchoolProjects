/*
** EPITECH PROJECT, 2020
** main
** File description:
** c
*/

#include <SFML/Graphics.h>
#include "defender.h"
#include "my.h"
#include "a_malloc.h"

int main(UNUSED int agrv, UNUSED char **argv)
{
    game_t *game = game_load();
    game_loop(game);
    a_malloc(A_MALLOC_FREE | A_LIST(1));
    a_malloc(A_MALLOC_FREE);
    return 0;
}
