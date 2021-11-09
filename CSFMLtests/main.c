/*
** EPITECH PROJECT, 2019
** Pathfinding project
** File description:
** 
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "map.h"
#include "chara.h"
#include "chara_movement.h"

#define PAUSE rand() % 180

char *fill_zero(void)
{
    char *buffer = malloc(sizeof(char) * 1024);
    for (int i = 0; i <= 1024; i++)
        buffer[i] = '0';
    return buffer;
}

int main(int argc, char **argv)
{
    sfVideoMode mode = {1792, 960, 32};
    sfRenderWindow *window;
    sfEvent event;
    map_t *map = malloc(sizeof(map_t));
    map->map_grid = malloc(sizeof(sfVector2f) * 28 * 15);
    map->map_grid = map_grid_init(28, 15);
    chara_data_t *lucina = lucina_init();
    chara_data_t *chrom = chrom_init();
    chara_data_t *olivia = olivia_init();
    chara_data_t *anna = anna_init();
    int *chrom_path = path_load(0, "path01");
    int *anna_path = path_load(1, "114223");
    char *pathfound = fill_zero();
    map->map = malloc(sizeof(char) * 436);
    if (argc == 1)
        map->map = map_load("map01");
    else
        map->map = map_load(argv[1]);
    pathfinding(map, chrom->position, lucina, pathfound, 0);
    my_putstr(pathfound);
    
    window = sfRenderWindow_create(mode, "Soopah Pathfindin'", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    long frame = 0;
    while (sfRenderWindow_isOpen(window)) {
        frame++;
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        map_sprite_management(window, map);
        if (anna_path[anna_path[0]] == 32066)
            anna_path[0] = 1;
        character_queueManagement(window, map, frame, anna, anna_path);
        character_idle(window, frame, chrom);
        character_randomMovement(window, map, frame, olivia);
        character_idle(window, frame, lucina);
        sfRenderWindow_display(window);
    }
    return 0;
}
