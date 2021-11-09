/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** h
*/

#ifndef TETRIS_H
#define TETRIS_H

/**************************************/

typedef struct vect {
    int x;
    int y;
}vect_t;

typedef struct current_tetrimino {
    int id;
    vect_t topl;
    int angle;
}ctetri_t;

typedef struct mapn {
    bool is_occupied;
    char c;
    int color;
}mapn_t;

typedef struct map {
    vect_t size;
    mapn_t ***mapn;
}map_t;

typedef struct tetriminos {
    char *name;
    vect_t size;
    char **body;
    int color;
}tetri_t;

typedef struct options {
    int level;
    int left_key;
    int right_key;
    int turn_key;
    int drop_key;
    int quit_key;
    int pause_key;
    vect_t map_size;
    bool help;
    bool wo_next;
    bool debug;
}opt_t;

typedef struct game {
    tetri_t **tetri;
    mapn_t ***mapn;
    ctetri_t *ctetri;
    opt_t *options;
}game_t;

/**************************************/

#define TETRI game->tetri
#define MAP game->map
#define MAPN game->mapn
#define CTETRI game->ctetri
#define CID game->ctetri->id
#define CANGLE game->ctetri->angle
#define CCOLOR TETRI[CID]->color
#define CBODY TETRI[CID]->body
#define CSIZE TETRI[CID]->size
#define CSIZEX TETRI[CID]->size.x
#define CSIZEY TETRI[CID]->size.y
#define LEVEL game->options->level
#define LEFT_KEY game->options->left_key
#define RIGHT_KEY game->options->right_key
#define TURN_KEY game->options->turn_key
#define DROP_KEY game->options->drop_key
#define QUIT_KEY game->options->quit_key
#define PAUSE_KEY game->options->pause_key
#define MAP_SIZE game->options->map_size
#define HELP game->options->help
#define WO_NEXT game->options->wo_next
#define DBG game->options->debug
#define XOFF 20

#define VECT(x, y) (vect_t){(x), (y)}
#define VECTADD(v1, v2) (vect_t){(v1).x + (v2).x, (v1).y + (v2).y)}
#define MAPNOCC(v) MAPN[(v).x][(v).y]->is_occupied
#define MAPNC(v) MAPN[(v).x][(v).y]->c
#define MAPNCOLOR(v) MAPN[(v).x][(v).y]->color

/**************************************/

char **list_tetrimino(void);
tetri_t **tetri_load(void);
game_t *game_load(int argc, char **argv);
int my_atoi(char *str);
char *file_load(char *filepath);
int options_load(game_t *game, int argc, char **argv);
char *mstrcat(char *str1, char *str2);
char *cpdelim(char **file, char c);
void debug(game_t *game);
void map_line_destroy(mapn_t **mapn);
mapn_t **init_line(game_t *game);
int init_map(game_t *game);
void display_management(game_t *game);
void display_board(game_t *game);
int game_loop(game_t *game);

/**************************************/



/**************************************/

#endif
