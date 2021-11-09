/*
** EPITECH PROJECT, 2019
** sokoban header
** File description:
** 
*/

#include <SFML/Graphics.h>

#ifndef MY_SOKOBAN_H
#define MY_SOKOBAN_H

/*************** DEFINES **************/

#define BOX game->box
#define BOX_C game->box_count
#define MAP game->map
#define P_POS game->player_pos
#define GOALS game->goal
#define GOALS_C game->goal_count
#define TEX game->tex
#define SPR game->spr
#define VMODE game->mode
#define WINDOW game->window
#define DRAW_MAP game->map->draw_map
#define SLOTS game->map->slots
#define MAXW game->maxw
#define MAXH game->maxh
#define MWIDTH game->map->width
#define MHEIGHT game->map->height
#define PLAYER_X game->player_pos.x
#define PLAYER_Y game->player_pos.y
#define ENLARGE_MSG "PLEASE ENLARGE TERMINAL"
#define RETURN_STATUS game->return_status
#define POS_UP(val) vect_init((val).x, (val).y - 1)
#define POS_DOWN(val) vect_init((val).x, (val).y + 1)
#define POS_LEFT(val) vect_init((val).x - 1, (val).y)
#define POS_RIGHT(val) vect_init((val).x + 1, (val).y)
#define GOAL 'O'
#define WALL '#'
#define LAND ' '
#define ARRAY_SIZE(x) (sizeof((x)) / sizeof(x[0]))

/*************** STRUCTS **************/

typedef struct {
    int ch;
    void (*fptr)();
}fptr_t;

typedef struct {
    int x;
    int y;
}vect_t;

typedef struct {
    vect_t pos;
    int type;
    int rand;
}slot_t;

typedef struct {
    char *draw_map;
    int width;
    int height;
    slot_t *slots;
}map_t;

typedef struct {
    int status;
    int id;
    vect_t pos;
}box_t;

typedef struct {
    sfTexture *spr_sheet;
    sfTexture *land;
    sfTexture *wall;
    sfTexture *exwall;
    sfTexture *box;
    sfTexture *goal;
}tex_t;

typedef struct {
    sfSprite *sprsh;
    sfSprite *land;
    sfSprite *wall;
    sfSprite *exwall;
    sfSprite *box;
    sfSprite *goal;
}spr_t;

typedef struct {
    map_t *map;
    box_t *box;
    tex_t *tex;
    spr_t *spr;
    vect_t *goal;
    char *map_path;
    sfVideoMode mode;
    sfRenderWindow *window;
    int goal_count;
    int box_count;
    int maxw;
    int maxh;
    vect_t player_pos;
}game_t;

/************* GAME LOAD **************/

game_t *game_load(char *filepath);
vect_t player_pos_init(map_t *map);
vect_t *goal_load(map_t *map, int goal_count);
box_t *box_load(map_t *map, int box_count);
char *raw_map_load(char *filepath);
slot_t *slot_init(map_t *map);
map_t *map_load(char *filepath);
int check_map_validity(game_t *game);
void game_reload(game_t *game);
void game_unload(game_t *game);
sfSprite *sprite_create(sfTexture *tex);
tex_t *tex_load(void);
spr_t *sprite_load(game_t *game);

/*************** MISC. ****************/

vect_t get_map_size(char *map);
vect_t vect_init(int x, int y);
vect_t vect_add(vect_t vect1, vect_t vect2);
vect_t vect_sub(vect_t vect1, vect_t vect2);
int get_occurences(char *map, char c);
sfIntRect sf_rect_init(int top, int left, int w, int h);
sfVideoMode video_mode_init(int w, int h);
sfVector2f sf_vect_init(float x, float y);

/************** GAME ******************/

void game_loop(game_t *game);
int is_game_over(game_t *game);
int get_return_status(game_t *game);

/************** EVENT *****************/

void event_management(game_t *game);
void key_press_management(game_t *game, sfKeyEvent event);

/*********** PLAYER MOVEMENT **********/

void player_move(game_t *game, vect_t vect);
int box_move(game_t *game, int id, vect_t dir);
int is_box(game_t *game, vect_t vect);
int can_move(game_t *game, vect_t vect);

/********* BOX STATUS REFRESH *********/

int slot_type(game_t *game, vect_t vect);
int is_stuck(game_t *game, int id);
void box_status_refresh(game_t *game);

/************* DISPLAY ****************/

void display_management(game_t *game);
void print_walls(game_t *game);
void print_boxes(game_t *game);
void print_player(game_t *game);

/************ SF DISPLAY **************/

void draw_sprite(game_t *game, sfSprite *sprite, sfVector2f vect);
void sf_draw_floor(game_t *game);
void sf_draw_exwall(game_t *game);
void sf_draw_walls(game_t *game);
void sf_draw_goals(game_t *game);
void sf_display_management(game_t *game);

/**************************************/

#endif
