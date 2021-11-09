/*
** EPITECH PROJECT, 2019
** map functions
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

sfVector2f *map_grid_init(int x, int y)
{
    int print_cnt = 0;
    sfVector2f *map_grid = malloc(sizeof(sfVector2f) * x * y);
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            map_grid[i * x + j].x = j * 64;
            map_grid[i * x + j].y = i * 64;
            my_putnbr(print_cnt);
            my_putstr("| y:");
            my_putnbr(map_grid[print_cnt].y);
            my_putstr(" x:");
            my_putnbr(map_grid[print_cnt].x);
            my_putstr(" |\n");
            print_cnt++;
        }
        my_putstr("\n");
    }
    return map_grid;
}

char *map_load(char *map_name)
{
    char buffer[435];
    char buffer2[420];
    int fd = 0;
    char *path = malloc(sizeof(char) * 5 + sizeof(char) * (my_strlen(map_name) + 1));
    my_strcat(path, "maps/");
    my_strcat(path, map_name);
    fd = open(path, O_RDONLY);
    read(fd, buffer, 435);
    buffer[435] = '\0';
    my_putstr(map_name);
    my_putstr(":\n");
    my_putstr(buffer);
    my_putstr("\n");
    int j = 0;
    for (int i = 0; i < 435; i++) {
        if (buffer[i] == '\n') {
            i++;
            buffer2[j] = buffer[i];
            j++;
        } else {
            buffer2[j] = buffer[i];
            j++;
        }
    }
    buffer2[420] = '\0';
    close(fd);
    char *buffer3 = my_strdup(buffer2);
    return buffer3;
}

int map_sprite_management(sfRenderWindow *window, map_t *map)
{
    sfSprite *land, *wall;
    sfTexture *landTex, *wallTex;
    landTex = sfTexture_createFromFile("sprites/land.png", NULL);
    land = sfSprite_create();
    sfSprite_setTexture(land, landTex, sfTrue);
    wallTex = sfTexture_createFromFile("sprites/wall.png", NULL);
    wall = sfSprite_create();
    sfSprite_setTexture(wall, wallTex, sfTrue);
    for (int i = 0; i < 420; i++) {
        if (map->map[i] == '0') {
            sfSprite_setPosition(land, map->map_grid[i]);
            sfRenderWindow_drawSprite(window, land, NULL);
        } else if (map->map[i] == '1') {
            sfSprite_setPosition(wall, map->map_grid[i]);
            sfRenderWindow_drawSprite(window, wall, NULL);
        }
    }
    sfSprite_destroy(land);
    sfSprite_destroy(wall);
    sfTexture_destroy(landTex);
    sfTexture_destroy(wallTex);
    return 0;
}
