/*
** EPITECH PROJECT, 2019
** load beatmap into ducks
** File description:
** 
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <fcntl.h>
#include "my.h"
#include "my_hunter.h"

int get_time_code(char *str, int *offset)
{
    int i = 0;
    char number[10];
    for (; str[i] != ','; i++)
        number[i] = str[i];
    number[i] = '\0';
    *offset += i + 1;
    return char_to_int(number);
}

int set_slot(char *slot, char *str)
{
    slot[0] = str[0];
    slot[1] = str[1];
    return 3;
}

int get_speed(char *str, int *offset)
{
    int i = 0;
    char number[10];
    for (; str[i] != '\n' && str[i] != '\0'; i++)
        number[i] = str[i];
    number[i] = '\0';
    *offset += i + 1;
    return char_to_int(number);
}

anim_t *init_anim_data(sfVideoMode *mode, char *slot, int speed)
{
    anim_t *anim_data = malloc(sizeof(anim_t));
    anim_data->pos.y = ((mode->height - 640) / 2) + 128 * (slot[1] - '0');
    anim_data->speed.y = 0;
    if (slot[0] == 'r') {
        anim_data->pos.x = mode->width - ((mode->width - 1200) / 2) - 128;
        anim_data->speed.x = -speed;
    } else if (slot[0] == 'l') {
        anim_data->pos.x = ((mode->width - 1200) / 2) + 8;
        anim_data->speed.x = speed;
    }
    return anim_data;
}

duck_t *load_ducks(game_t *game, char *str)
{
    int ret = get_ret_count(str) + 1;
    duck_t *duck = malloc(sizeof(duck_t) * (ret + 1));
    int offset = 0;
    int i = 0;
    for (; i < ret; i++) {
        duck[i].time_code = get_time_code((str + offset), &offset);
        offset += set_slot(duck[i].slot, (str + offset));
        duck[i].speed = get_speed((str + offset), &offset);
        duck[i].status = 0;
        duck[i].scored = -1;
        duck[i].anim_data = init_anim_data(game->mode,
        duck[i].slot, duck->speed);
    }
    game->duck_amnt = i;
    duck[i].status = -1;
    return duck;
}
