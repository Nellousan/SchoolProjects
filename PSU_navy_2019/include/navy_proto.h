/*
** EPITECH PROJECT, 2020
** navy h
** File description:
** h
*/

#ifndef NAVY_PROTO
#define NAVY_PROTO

#include <stdbool.h>
#include <signal.h>

game_t *game_load(int argc, char **argv);
int display_board(game_t *game);
int boats_placing(game_t *game);
char *file_load(char *filepath);
char *copy_until(char **str, char c);
int char_to_int(char *str);
int is_num(char *str);
int establish_connection(game_t *game);
int game_loop(game_t *game);
bool check_validity(char *buffer);
vect_t extract_vect(char *str);
int turn_attack(game_t *game);
int turn_wait(game_t *game);
void usleepy_kill(int sleep_time, pid_t pid, int sig);
void pause_usleep(int sleep_time);
boats_t *boats_load(char *str);
int set_destr(vect_t v1, vect_t v2, boats_t *boats);
int set_sub(vect_t v1, vect_t v2, boats_t *boats);
int set_battleship(vect_t v1, vect_t v2, boats_t *boats);
int set_cruiser(vect_t v1, vect_t v2, boats_t *boats);

#endif
