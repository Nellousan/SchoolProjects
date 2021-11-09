/*
** EPITECH PROJECT, 2020
** turn
** File description:
** need
*/

#include "my.h"
#include "get_next_line.h"
#include "n4s.h"

static bool turn3(float middle, float direction)
{
    if (middle >= 200 && middle < 400) {
        if (direction < 0) {
            my_putstr("WHEELS_DIR:-0.3\n");
            return verif_end(get_next_line(STDIN_FILENO));
        } else {
            my_putstr("WHEELS_DIR:0.3\n");
            return verif_end(get_next_line(STDIN_FILENO));
        }
    }
    if (middle < 200) {
        if (direction < 0) {
            my_putstr("WHEELS_DIR:-0.5\n");
            return verif_end(get_next_line(STDIN_FILENO));
        } else {
            my_putstr("WHEELS_DIR:0.5\n");
            return verif_end(get_next_line(STDIN_FILENO));
        }
    }
    return false;
}

static bool turn2(float middle, float direction)
{
    if (middle >= 600 && middle < 1000) {
        if (direction < 0) {
            my_putstr("WHEELS_DIR:-0.1\n");
            return verif_end(get_next_line(STDIN_FILENO));
        } else {
            my_putstr("WHEELS_DIR:0.1\n");
            return verif_end(get_next_line(STDIN_FILENO));
        }
    }
    if (middle >= 400 && middle < 600) {
        if (direction < 0) {
            my_putstr("WHEELS_DIR:-0.2\n");
            return verif_end(get_next_line(STDIN_FILENO));
        } else {
            my_putstr("WHEELS_DIR:0.2\n");
            return verif_end(get_next_line(STDIN_FILENO));
        }
    }
    return turn3(middle, direction);
}

bool turn(float middle, float direction)
{
    if (middle >= 1500) {
        if (direction < 0) {
            my_putstr("WHEELS_DIR:-0.005\n");
            return verif_end(get_next_line(STDIN_FILENO));
        } else {
            my_putstr("WHEELS_DIR:0.005\n");
            return verif_end(get_next_line(STDIN_FILENO));
        }
    }
    if (middle >= 1000 && middle < 1500) {
        if (direction < 0) {
            my_putstr("WHEELS_DIR:-0.05\n");
            return verif_end(get_next_line(STDIN_FILENO));
        } else {
            my_putstr("WHEELS_DIR:0.05\n");
            return verif_end(get_next_line(STDIN_FILENO));
        }
    }
    return turn2(middle, direction);
}