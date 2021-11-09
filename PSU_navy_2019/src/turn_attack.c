/*
** EPITECH PROJECT, 2020
** attacking turn
** File description:
** c
*/

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <stdbool.h>
#include "my.h"
#include "navy.h"

static int manage_hit(game_t *game, vect_t hitpos)
{
    int map_index = (hitpos.x - 1) + (hitpos.y - 1) * 8;
    pause();
    if (GET_HITPOS == 0 || (GET_HITPOS == 1 && TMAP[map_index]->hit != 0)) {
        my_printf("missed\n");
        if (TMAP[map_index]->hit == 0)
            TMAP[map_index]->hit = 2;
    } else {
        my_printf("hit\n");
        TMAP[map_index]->hit = 1;
    }
    return 0;
}

static vect_t read_attack(void)
{
    size_t n = 0;
    char *buffer = NULL;
    bool pass = false;
    vect_t hitpos;
    while (pass == false) {
        my_printf("attack: ");
        getline(&buffer, &n, stdin);
        pass = check_validity(buffer);
        if (pass == false) {
            my_printf("wrong position\n");
            free(buffer);
            buffer = NULL;
            n = 0;
        }
    }
    buffer[2] = '\0';
    my_printf("%s: ", buffer);
    hitpos = extract_vect(buffer);
    free(buffer);
    return hitpos;
}

static void attack_handle(int signum)
{
    if (signum == SIGUSR2)
        GET_HITPOS = 1;
    else
        GET_HITPOS = 0;
    return;
}

static int send_signal(game_t *game, vect_t hitpos)
{
    for (int i = 0; i < hitpos.x; i++) {
        usleepy_kill(70000, E_PID, SIGUSR1);
        pause();
    }
    usleepy_kill(70000, E_PID, SIGUSR2);
    pause();
    for (int i = 0; i < hitpos.y; i++) {
        usleepy_kill(70000, E_PID, SIGUSR1);
        pause();
    }
    usleepy_kill(70000, E_PID, SIGUSR2);
    pause();
    return 0;
}

int turn_attack(game_t *game)
{
    struct sigaction sigact = {0};
    vect_t hitpos;
    sigact.sa_handler = &attack_handle;
    sigemptyset(&sigact.sa_mask);
    GET_HITPOS = 0;
    sigaction(SIGUSR1, &sigact, NULL);
    sigaction(SIGUSR2, &sigact, NULL);
    hitpos = read_attack();
    send_signal(game, hitpos);
    manage_hit(game, hitpos);
    my_printf("\n");
    return 1;
}
