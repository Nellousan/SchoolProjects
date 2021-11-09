/*
** EPITECH PROJECT, 2019
** my_hunter main
** File description:
** 
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my.h"
#include "my_hunter.h"

int main(int argc, char **argv)
{
    if (syntax_check(argc, argv) == 84)
        return 84;
    game_t *game = load_game(argv[1]);
    if (game == NULL)
        return 84;
    start_game(game);
    display_result_screen(game);
    unload_game(game);
    return 0;
}
