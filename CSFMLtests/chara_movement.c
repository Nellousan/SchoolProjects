/*
** EPITECH PROJECT, 2019
** character_movement
** File description:
** 
*/

//TO DO: Modifer canpass pour utiliser dans pathfinding

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

#define SPEED 2
#define PAUSE rand() % 180 * 2 / SPEED

int character_bonk(char *direction, sfRenderWindow *window, map_t *map, chara_data_t *chara_data)
{

}

int character_canPass(char *direction, map_t *map, chara_data_t *chara_data)
{
    if (!my_strcmp(direction, "up")) {
        if (chara_data->position.y == 0)
            return 0;
        for (int i = 0; i < 420; i++) {
            if (chara_data->position.x == map->map_grid[i].x && chara_data->position.y == map->map_grid[i].y + 64)
                if (map->map[i] == '1')
                    return 0;
                else
                    return 1;
        }
    } else if (!my_strcmp(direction, "down")) {
        if (chara_data->position.y == 960)
            return 0;
        for (int i = 0; i < 420; i++) {
            if (chara_data->position.x == map->map_grid[i].x && chara_data->position.y == map->map_grid[i].y - 64)
                if (map->map[i] == '1')
                    return 0;
                else
                    return 1;
        }
    } else if (!my_strcmp(direction, "left")) {
        if (chara_data->position.x == 0)
            return 0;
        for (int i = 0; i < 420; i++) {
            if (chara_data->position.x == map->map_grid[i].x + 64 && chara_data->position.y == map->map_grid[i].y)
                if (map->map[i] == '1')
                    return 0;
                else
                    return 1;
        }
    } else if (!my_strcmp(direction, "right")) {
        if (chara_data->position.x == 1792)
            return 0;
        for (int i = 0; i < 420; i++) {
            if (chara_data->position.x == map->map_grid[i].x - 64 && chara_data->position.y == map->map_grid[i].y)
                if (map->map[i] == '1')
                    return 0;
                else
                    return 1;
        }
    }
}

int character_moveUp(sfRenderWindow *window, map_t *map, long frame, chara_data_t *chara_data)
{
    if (frame % 10 == 0) {
        if (chara_data->anim_frame == 3)
            chara_data->anim_frame = 0;
        else
            chara_data->anim_frame++;
    }
    chara_data->chara_i = sfImage_createFromFile(chara_data->map_sprite);
    sfIntRect rect = {chara_data->anim_frame * 64, 5 * 64, 64, 64};
    chara_data->chara_s = sfSprite_create();
    chara_data->charaTex = sfTexture_createFromImage(chara_data->chara_i, &rect);
    sfSprite_setTexture(chara_data->chara_s, chara_data->charaTex, sfTrue);
    if (character_canPass("up", map, chara_data))
        chara_data->position.y -= SPEED;
    sfSprite_setPosition(chara_data->chara_s, chara_data->position);
    sfRenderWindow_drawSprite(window, chara_data->chara_s, NULL);
    sfImage_destroy(chara_data->chara_i);
    sfSprite_destroy(chara_data->chara_s);
    sfTexture_destroy(chara_data->charaTex);
    for (int i = 0; i < 420; i++) {
        if (map->map_grid[i].y == chara_data->position.y) {
            chara_data->status = 0;
            chara_data->grid_pos.y--;
            return 1;
        }
    }
    chara_data->status = 1;
    /*} else {
      chara_data->status = 0;
      chara_data->pause_frame = 15;
      //my_putstr("bonk up.\n");
      }*/
    return 0;
}

int character_moveDown(sfRenderWindow *window, map_t *map, long frame, chara_data_t *chara_data)
{
    if (frame % 10 == 0) {
        if (chara_data->anim_frame == 3)
            chara_data->anim_frame = 0;
        else
            chara_data->anim_frame++;
    }
    chara_data->chara_i = sfImage_createFromFile(chara_data->map_sprite);
    sfIntRect rect = {chara_data->anim_frame * 64, 4 * 64, 64, 64};
    chara_data->chara_s = sfSprite_create();
    chara_data->charaTex = sfTexture_createFromImage(chara_data->chara_i, &rect);
    sfSprite_setTexture(chara_data->chara_s, chara_data->charaTex, sfTrue);
    if(character_canPass("down", map, chara_data))
        chara_data->position.y += SPEED;
    sfSprite_setPosition(chara_data->chara_s, chara_data->position);
    sfRenderWindow_drawSprite(window, chara_data->chara_s, NULL);
    sfImage_destroy(chara_data->chara_i);
    sfSprite_destroy(chara_data->chara_s);
    sfTexture_destroy(chara_data->charaTex);
    for (int i = 0; i < 420; i++) {
        if (map->map_grid[i].y == chara_data->position.y) {
            chara_data->status = 0;
            chara_data->grid_pos.y++;
            return 1;
        }
    }
    chara_data->status = 2;
    /*} else {
      chara_data->status = 0;
      chara_data->pause_frame = 15;
      //my_putstr("bonk down.\n");
      }*/
    return 0;
}

int character_moveLeft(sfRenderWindow *window, map_t *map, long frame, chara_data_t *chara_data)
{
    if (frame % 10 == 0) {
        if (chara_data->anim_frame == 3)
            chara_data->anim_frame = 0;
        else
            chara_data->anim_frame++;
    }
    chara_data->chara_i = sfImage_createFromFile(chara_data->map_sprite);
    sfIntRect rect = {chara_data->anim_frame * 64, 2 * 64, 64, 64};
    chara_data->chara_s = sfSprite_create();
    chara_data->charaTex = sfTexture_createFromImage(chara_data->chara_i, &rect);
    sfSprite_setTexture(chara_data->chara_s, chara_data->charaTex, sfTrue);
    if (character_canPass("left", map, chara_data))
        chara_data->position.x -= SPEED;
    sfSprite_setPosition(chara_data->chara_s, chara_data->position);
    sfRenderWindow_drawSprite(window, chara_data->chara_s, NULL);
    sfImage_destroy(chara_data->chara_i);
    sfSprite_destroy(chara_data->chara_s);
    sfTexture_destroy(chara_data->charaTex);
    for (int i = 0; i < 420; i++) {
        if (map->map_grid[i].x == chara_data->position.x) {
            chara_data->status = 0;
            chara_data->grid_pos.x--;
            return 1;
        }
    }
    chara_data->status = 3;
    /*} else {
      chara_data->status = 0;
      chara_data->pause_frame = 15;
      my_putstr("bonk left.\n");
      }*/
    return 0;
}

int character_moveRight(sfRenderWindow *window, map_t *map, long frame, chara_data_t *chara_data)
{
    if (frame % 10 == 0) {
        if (chara_data->anim_frame == 3)
            chara_data->anim_frame = 0;
        else
            chara_data->anim_frame++;
    }
    chara_data->chara_i = sfImage_createFromFile(chara_data->map_sprite);
    sfIntRect rect = {chara_data->anim_frame * 64, 3 * 64, 64, 64};
    chara_data->chara_s = sfSprite_create();
    chara_data->charaTex = sfTexture_createFromImage(chara_data->chara_i, &rect);
    sfSprite_setTexture(chara_data->chara_s, chara_data->charaTex, sfTrue);
    if (character_canPass("right", map, chara_data))
        chara_data->position.x += SPEED;
    sfSprite_setPosition(chara_data->chara_s, chara_data->position);
    sfRenderWindow_drawSprite(window, chara_data->chara_s, NULL);
    sfImage_destroy(chara_data->chara_i);
    sfSprite_destroy(chara_data->chara_s);
    sfTexture_destroy(chara_data->charaTex);
    for (int i = 0; i < 420; i++) {
        if (map->map_grid[i].x == chara_data->position.x) {
            chara_data->status = 0;
            chara_data->grid_pos.x++;
            return 1;
        }
    }
    chara_data->status = 4;
    /* } else {
       chara_data->status = 0;
       chara_data->pause_frame = 15;
       my_putstr("bonk right.\n");
       }*/
    return 0;
}

int character_idle(sfRenderWindow *window, long frame, chara_data_t *chara_data)
{
    chara_data->pause_frame = (chara_data->pause_frame > 0) ? --chara_data->pause_frame : 0;
    if (frame % 15 == 0) {
        if (chara_data->anim_frame == 3)
            chara_data->anim_frame = 0;
        else
            chara_data->anim_frame++;
    }
    chara_data->chara_i = sfImage_createFromFile(chara_data->map_sprite);
    sfIntRect rect = {chara_data->anim_frame * 64, 0, 64, 64};
    chara_data->chara_s = sfSprite_create();
    chara_data->charaTex = sfTexture_createFromImage(chara_data->chara_i, &rect);
    sfSprite_setTexture(chara_data->chara_s, chara_data->charaTex, sfTrue);
    sfSprite_setPosition(chara_data->chara_s, chara_data->position);
    sfRenderWindow_drawSprite(window, chara_data->chara_s, NULL);
    sfImage_destroy(chara_data->chara_i);
    sfSprite_destroy(chara_data->chara_s);
    sfTexture_destroy(chara_data->charaTex);
    chara_data->status = 0;
    return 0;
}

int character_randomMovement(sfRenderWindow *window, map_t *map, long frame, chara_data_t *chara_data)
{
    if (chara_data->status == 0 && chara_data->pause_frame == 0)
        chara_data->status = rand() % 5;
    if (chara_data->status == 1 && chara_data->pause_frame == 0 && character_canPass("up", map, chara_data))
        character_moveUp(window, map, frame, chara_data);
    else if (chara_data->status == 2 && chara_data->pause_frame == 0 && character_canPass("down", map, chara_data))
        character_moveDown(window, map, frame, chara_data);
    else if (chara_data->status == 3 && chara_data->pause_frame == 0 && character_canPass("left", map, chara_data))
        character_moveLeft(window, map, frame, chara_data);
    else if (chara_data->status == 4 && chara_data->pause_frame == 0 && character_canPass("right", map, chara_data))
        character_moveRight(window, map, frame, chara_data);
    //if (chara_data->status == 0)
    else {
        chara_data->pause_frame = (chara_data->pause_frame == 0) ? PAUSE : chara_data->pause_frame;
        character_idle(window, frame, chara_data);
    }
}

int character_queueManagement(sfRenderWindow *window, map_t *map, long frame, chara_data_t *chara_data, int *q)
{
    if (q[q[0]] == 32066) {
        character_idle(window, frame, chara_data);
    } else if (q[q[0]] == 1) {
        int tmp = character_moveUp(window, map, frame, chara_data);
        if (tmp)
            q[0]++;
    } else if (q[q[0]] == 2) {
        int tmp = character_moveDown(window, map, frame, chara_data);
        if (tmp)
            q[0]++;
    } else if (q[q[0]] == 3) {
        int tmp = character_moveLeft(window, map, frame, chara_data);
        if (tmp)
            q[0]++;
    } else if (q[q[0]] == 4) {
        int tmp = character_moveRight(window, map, frame, chara_data);
        if (tmp)
            q[0]++;
    }
}

int *path_load(int mode, char *path)
{
    if (mode == 0) {
        char buffer[2048];
        int size;
        int fd;
        char *file_path = malloc(sizeof(char) * 6 + sizeof(char) * (my_strlen(path) + 1));
        my_strcat(file_path, "paths/");
        my_strcat(file_path, path);
        fd = open(file_path, O_RDONLY);
        size = read(fd, buffer, 2047);
        buffer[size] = '\0';
        my_putstr(path);
        my_putstr(":\n");
        my_putstr(buffer);
        my_putstr("\n");
        
        int *intbuffer = malloc(sizeof(int) * (size + 2));
        intbuffer[0] = 1;
        for (int i = 0; buffer[i] != '\0'; i++) {
            intbuffer[i + 1] = buffer[i] - '0';
            intbuffer[i + 2] = 32066;
        }
        return intbuffer;
    } else  if (mode == 1) {
        int *intbuffer = malloc(sizeof(int) * (my_strlen(path) + 2));
        intbuffer[0] = 1;
        for (int i = 0; path[i] != '\0'; i++) {
            intbuffer[i + 1] = path[i] - '0';
            intbuffer[i + 2] = 32066;
        }
        return intbuffer;
    }
}

char *pathfinding(map_t *map, sfVector2f goal, chara_data_t *chara_data, char *path, int i)
{

    if ((chara_data->position.x == goal.x && chara_data->position.y == goal.y) || i > 10) {
        path[i] = '\0';
        return path;
    }
    if (character_canPass("up", map, chara_data)) {
        my_putstr("up ");
        chara_data->position.y -= 64;
        path[i] = '1';
        pathfinding(map, goal, chara_data, path, ++i);
        i--;
        chara_data->position.y += 64;
        for (int j = 0; j < 1024; j++)
            if (path[j] == '\0')
                return path;
    }
    if (character_canPass("left", map, chara_data)) {
        my_putstr("left ");
        chara_data->position.x -= 64;
        path[i] = '3';
        pathfinding(map, goal, chara_data, path, ++i);
        i--;
        chara_data->position.x += 64;
        for (int j = 0; j < 1024; j++)
            if (path[j] == '\0')
                return path;
    }
    if (character_canPass("down", map, chara_data)) {
        my_putstr("down ");
        chara_data->position.y += 64;
        path[i] = '2';
        pathfinding(map, goal, chara_data, path, ++i);
        i--;
        chara_data->position.y -= 64;
        for (int j = 0; j < 1024; j++)
            if (path[j] == '\0')
                return path;
    }
    if (character_canPass("right", map, chara_data)) {
        my_putstr("right ");
        chara_data->position.x += 64;
        path[i] = '4';
        pathfinding(map, goal, chara_data, path, ++i);
        i--;
        chara_data->position.x -= 64;
        for (int j = 0; j < 1024; j++)
            if (path[j] == '\0')
                return path;
    }
    
}
