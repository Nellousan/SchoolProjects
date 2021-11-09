/*
** EPITECH PROJECT, 2020
** speed
** File description:
** need
*/

#include "my.h"
#include "get_next_line.h"
#include "n4s.h"

static bool change_speed2(float middle)
{
    if (middle >= 600 && middle < 1000) {
        my_putstr("CAR_FORWARD:0.4\n");
        return verif_end(get_next_line(STDIN_FILENO));
    }
    if (middle >= 400 && middle < 600) {
        my_putstr("CAR_FORWARD:0.2\n");
        return verif_end(get_next_line(STDIN_FILENO));
    }
    if (middle < 400) {
        my_putstr("CAR_FORWARD:0.1\n");
        return verif_end(get_next_line(STDIN_FILENO));
    }
    return false;
}

bool change_speed(float middle)
{
    if (middle >= 2000) {
        my_putstr("CAR_FORWARD:1\n");
        return verif_end(get_next_line(STDIN_FILENO));
    }
    if (middle >= 1500 && middle < 2000) {
        my_putstr("CAR_FORWARD:0.8\n");
        return verif_end(get_next_line(STDIN_FILENO));
    }
    if (middle >= 1000 && middle < 1500) {
        my_putstr("CAR_FORWARD:0.5\n");
        return verif_end(get_next_line(STDIN_FILENO));
    }
    return change_speed2(middle);
}