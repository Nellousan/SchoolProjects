/*
** EPITECH PROJECT, 2020
** misc
** File description:
** c
*/

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>
#include "my.h"
#include "navy.h"

int is_num(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] > '9' || str[i] < '0')
            return 0;
    return 1;
}

void reset_handle(UNUSED int signum, UNUSED siginfo_t *sig, UNUSED void *c)
{
    return;
}

bool check_validity(char *buffer)
{
    if (my_strlen(buffer) != 3)
        return false;
    if (buffer[0] < 'A' || buffer[0] > 'H')
        return false;
    if (buffer[1] < '1' || buffer[1] > '8')
        return false;
    return true;
}

void usleepy_kill(int sleep_time, pid_t pid, int sig)
{
    usleep(sleep_time);
    kill(pid, sig);
}

void pause_usleep(int sleep_time)
{
    pause();
    usleep(sleep_time);
}
