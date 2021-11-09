/*
** EPITECH PROJECT, 2019
** miscellaneous functions
** File description:
** 
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <fcntl.h>
#include "my.h"
#include "my_hunter.h"

int get_ret_count(char *str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n')
            count++;
    return count;
}

long get_time(sfClock *clock)
{
    sfTime sftime = sfClock_getElapsedTime(clock);
    long time = sftime.microseconds;
    return time;
}

sfVector2f sf_vector_init(float x, float y)
{
    sfVector2f vect;
    vect.x = x;
    vect.y = y;
    return vect;
}

char *copy_until(char *str, char c)
{
    int i = 0;
    char *buffer;
    for (; str[i] != c; i++);
    buffer = malloc(sizeof(char) * (i + 1));
    for (i = 0; str[i] != c; i++)
        buffer[i] = str[i];
    buffer[i] = '\0';
    return buffer;
}

int char_to_int(char *str)
{
    int nb = 0;
    int len = my_strlen(str) - 1;
    for (int i = 0; str[i] != '\0'; i++, len--)
        nb += (str[i] - '0') * my_pow(10, len);
    return nb;
}
