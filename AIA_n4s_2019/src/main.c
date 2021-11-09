/*
** EPITECH PROJECT, 2020
** steek
** File description:
** main
*/

#include "my.h"
#include "get_next_line.h"
#include "n4s.h"

static bool action(char **infos)
{
    float right = atof(infos[34]);
    float middle = atof(infos[15]);
    float left = atof(infos[4]);
    if (turn(middle, left - right) == true)
        return true;
    if (change_speed(middle) == true)
        return true;
    return false;
}

static void loop(char *str)
{
    char **infos;

    while (1) {
        str = NULL;
        my_putstr("GET_INFO_LIDAR\n");
        str = get_next_line(0);
        infos = my_str_to_array(str);
        if (infos[35] == NULL)
            continue;
        if (my_strcomp(infos[35], "Track Cleared") == true)
            break;
        if (action(infos) == true)
            break;
    }
}

int main(void)
{
    char *str = NULL;

    my_putstr("start_simulation\n");
    my_putstr("CAR_FORWARD:0.5\n");
    loop(str);
    my_putstr("stop_simulation\n");
    return 0;
}