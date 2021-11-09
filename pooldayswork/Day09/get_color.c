/*
** EPITECH PROJECT, 2019
** get color
** File description:
** return int color value from r,g,b 
*/

#include "my.h"

int get_color(unsigned char red, unsigned char green, unsigned char blue)
{
    int result = (red << 16) + (green << 8) + (blue << 0);
    return result;
}
