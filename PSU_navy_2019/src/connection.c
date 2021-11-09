/*
** EPITECH PROJECT, 2020
** connection establishing functions
** File description:
** aza
*/

#include <signal.h>
#include <unistd.h>
#include "my.h"
#include "navy.h"

static void wait_handle(int signum, siginfo_t *siginfo, UNUSED void *c)
{
    if (signum == SIGUSR1)
        GET_HITPOS = siginfo->si_pid;
    return;
}

int establish_connection(game_t *game)
{
    struct sigaction sigact1;
    sigact1.sa_sigaction = &wait_handle;
    sigact1.sa_flags = SA_SIGINFO;
    sigemptyset(&sigact1.sa_mask);
    sigaction(SIGUSR1, &sigact1, NULL);
    sigaction(SIGUSR2, &sigact1, NULL);
    my_printf("my_pid: %d\n", getpid());
    if (PLAYER == 1) {
        my_printf("waiting for enemy connection...\n\n");
        pause_usleep(2000);
        E_PID = GET_HITPOS;
        GET_HITPOS = 0;
        usleepy_kill(70000, E_PID, SIGUSR2);
        my_printf("enemy connected\n\n");
    } else {
        kill(E_PID, SIGUSR1);
        pause_usleep(2000);
        my_printf("successfully connected\n\n");
    }
    return 0;
}
