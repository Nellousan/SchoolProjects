/*
** EPITECH PROJECT, 2019
** chara_movement header
** File description:
** 
*/

int character_bonk(char *direction, sfRenderWindow *window,  map_t *map, chara_data_t *chara_data);
int character_canPass(char *direction, map_t *map, chara_data_t *chara_data);
int character_moveUp(sfRenderWindow *window, map_t *map, long frame, chara_data_t *chara_data);
int character_moveDown(sfRenderWindow *window, map_t *map, long frame, chara_data_t *chara_data);
int character_moveLeft(sfRenderWindow *window, map_t *map, long frame, chara_data_t *chara_data);
int character_moveRight(sfRenderWindow *window, map_t *map, long frame, chara_data_t *chara_data);
int character_idle(sfRenderWindow *window, long frame, chara_data_t *chara_data);
int character_randomMovement(sfRenderWindow *window, map_t *map, long frame, chara_data_t *chara_data);
int character_queueManagement(sfRenderWindow *window, map_t *map, long frame, chara_data_t *chara_data, int *q);
int *path_load(int mode, char *path);
char *pathfinding(map_t *map, sfVector2f goal, chara_data_t *chara_data, char *path, int i);
