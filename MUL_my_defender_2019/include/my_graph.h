/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** obiwan kenobi
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>

struct enemy {
    int hp;
    int speed;
    int status;
    sfVector2f coord;
    sfSprite *sprite;
};
typedef struct enemy enemy_t;

enemy_t **create_enemy_tab(void);
sfRectangleShape ***create_cadriage(char *filepath);
