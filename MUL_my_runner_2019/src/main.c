/*
** EPITECH PROJECT, 2019
** my_runner main
** File description:
** 
*/

#include <stdlib.h>
#include <math.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my.h"
#include "my_runner.h"

int main(int argc, char **argv)
{
    game_t *game;
    if (argc < 2)
        return 84;
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        cat_help();
        return 0;
    }
    game = game_load(argv[1]);
    if (game == NULL)
        return 84;
    print_entity_list(game);
    print_player(game);
    print_player_atk(game);
    print_map_data(game);
    global_parameter_init(game);
    game_status_selector(game);
    return 0;
}
