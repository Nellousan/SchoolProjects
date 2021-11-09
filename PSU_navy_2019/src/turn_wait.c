/*
** EPITECH PROJECT, 2020
** waiting turn
** File description:
** a
*/

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include "my.h"
#include "navy.h"

static void wait_handle(int signum, siginfo_t *sig, UNUSED void *c)
{
    ADD_ITERATION(GET_HITPOS);
    if (signum == SIGUSR2)
        ADD_CONTINUE(GET_HITPOS);
    else if (GET_CONTINUE(GET_HITPOS) == 0)
        ADD_HITPOSX(GET_HITPOS);
    else
        ADD_HITPOSY(GET_HITPOS);
    usleepy_kill(100, sig->si_pid, SIGUSR1);
    return;
}

static void manage_hit(game_t *game, vect_t pos)
{
    int sig = 0;
    int map_index = (pos.x - 1) + (pos.y - 1) * 8;
    my_printf("%c%d: ", pos.x + 'A' - 1, pos.y);
    if (MAP[map_index]->ship != 0 && MAP[map_index]->hit == 0) {
        my_printf("hit\n\n");
        sig = SIGUSR2;
        MAP[map_index]->hit = 1;
    } else {
        my_printf("missed\n\n");
        sig = SIGUSR1;
        if (MAP[map_index]->hit == 0)
            MAP[map_index]->hit = 2;
    }
    usleepy_kill(100, E_PID, sig);
    return;
}

int turn_wait(game_t *game)
{
    struct sigaction sigact= {0};
    vect_t hitpos;
    sigact.sa_sigaction = &wait_handle;
    sigact.sa_flags = SA_SIGINFO;
    sigemptyset(&sigact.sa_mask);
    GET_HITPOS = 0;
    sigaction(SIGUSR1, &sigact, NULL);
    sigaction(SIGUSR2, &sigact, NULL);
    my_printf("waiting for enemy's attack...\n");
    while (GET_CONTINUE(GET_HITPOS) != 2) {
        pause_usleep(2000);
    }
    hitpos = VECT(GET_HITPOSX(GET_HITPOS), GET_HITPOSY(GET_HITPOS));
    manage_hit(game, hitpos);
    return 0;
}
