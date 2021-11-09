/*
** EPITECH PROJECT, 2019
** actual game loop
** File description:
** 
*/

#include <stdlib.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include "my.h"
#include "my_hunter.h"

int duck_beat_texture_management(game_t *game);

int check_all_ducks_dead(game_t *game)
{
    int i = 0;
    for (; DUCK_I.status != -1; i++)
        if (DUCK_I.status != 2)
            return 0;
    i--;
    if (TIME < DUCK_I.time_code + 700)
        return 0;
    return 1;
}

int wait_screen(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_display(game->window);
    while (TIME < 1000);
    sfClock_restart(game->clock);
    return 0;
}

int start_game(game_t *game)
{
    game->window = sfRenderWindow_create(*game->mode,
    "Soopah Hunter", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(WINDOW, 60);
    sfRenderWindow_setMouseCursorVisible(WINDOW, sfFalse);
    game->clock = sfClock_create();
    draw_border_rects(game);
    game->status = 1;
    wait_screen(game);
    sfMusic_play(game->sound->music);
    while (sfRenderWindow_isOpen(game->window)) {
        if (check_all_ducks_dead(game))
            break;
        duck_die_refresh(game);
        duck_beat_texture_management(game);
        display_management(game);
        event_management(game);
    }
    return 0;
}
