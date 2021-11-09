/*
** EPITECH PROJECT, 2019
** My runner header
** File description:
** 
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>

#ifndef MY_RUNNER
#define MY_RUNNER

/************** DEFINES ***************/

#define OBJ game->obj
#define TEX game->tex
#define SPR game->spr
#define MAP game->map
#define O_MAP game->map->o_map
#define E_MAP game->map->e_map
#define KEY game->key
#define CLOCK game->clock
#define TIME game->time
#define G_STATUS game->game_status
#define G_OVER game->game_over
#define TS game->title_screen
#define END game->end_screen
#define HUD game->hud
#define MTIME (game->time.microseconds / 1000)
#define WINDOW game->window
#define VMODE game->mode
#define BCKG game->spr->background
#define E_LIST game->e_list
#define PLAYER game->player
#define CURSOR_POS game->cursor_pos
#define MOUSE_CLICK game->mouse_click
#define P_ATK game->player->player_atk
#define P_POS game->player->pos
#define P_ATKID game->player->atk_id
#define P_ANIMD game->player->anim_data
#define P_STATUS game->player->status
#define P_SSIZE game->player->sprite_rect.height
#define P_SWIDTH game->player->sprite_rect.width
#define P_FRAME game->player->frame
#define P_HURT game->player->hurtbox
#define OBJ_HURT obj->hurtbox
#define OBJ_FRAME obj->frame
#define OBJ_STATUS obj->e_status
#define OBJ_ID obj->id
#define OBJ_ANIMD E_LIST[OBJ_ID]->anim_data
#define VHEIGHT game->mode.height
#define VWIDTH game->mode.width
#define IS_AIRBORN(game) (P_STATUS == rise || P_STATUS == fall) ? 1 : 0
#define DEC(value) ((value) - '0')
#define MSEC(value) ((value).microseconds / 1000)
#define SPR_DIR "sprites/"
#define WINNAME "Soopah Runner"
#define RIGHT 1
#define LEFT 2
#define vec2f(x, y) ((sfVector2f){x, y})
#define rect(l, t, w, h) ((sfIntRect){l, t, w, h})
#define rect_topleft(rect) ((sfVector2f){rect.left, rect.top})
#define rect_topright(rect) ((sfVector2f){rect.left + rect.width, rect.top})
#define rect_botleft(rect) ((sfVector2f){rect.left, rect.top + rect.height})
#define rect_botright(r) ((sfVector2f){r.left + r.width, r.top + r.height})
#define sf_color(r, g, b, a) ((sfColor){r, g, b, a})
#define DMG_COLOR sf_color(255, 125, 125, 255)
#define P_DMG_COLOR sf_color(255, 125, 125, 170)
#define RESET_COLOR sf_color(255, 255, 255, 255)
#define PHURT_COLOR sf_color(0, 0, 255, 100)
#define OHURT_COLOR sf_color(0, 255, 0, 100)
#define EHURT_COLOR sf_color(255, 0, 0, 100)

/*************** ENUM *****************/

typedef enum {
    o_run,
    o_atk,
    o_dying
}o_anime_e;
    
typedef enum {
    idle,
    run,
    crouch,
    rise,
    fall,
    atk,
    dying
}anim_e;

typedef enum {
    menu,
    stage,
    death,
    end,
    quit
}menu_e;

/************** STRUCTS ***************/

typedef struct game game_t;

typedef struct obj {
    int obj_status;
    int id;
    int type;
    char *name;
    int hp;
    int e_status;
    int behaviour;
    int frame;
    int damage;
    int run_spd;
    int facing;
    sfSprite ***sprite;
    sfVector2f pos;
    sfIntRect hitbox;
    sfIntRect hurtbox;
    sfTime pos_time;
    sfTime spawn_time;
    sfTime attack_time;
    sfTime status_time;
    sfTime frame_time;
    sfTime dmg_time;
    sfMusic *hitsound;
    sfMusic *attack_sound;
}obj_t;

typedef struct behaviour {
    int bhv;
    void (*fptr)(game_t *game, obj_t *obj);
}bhv_t;

typedef struct anim_node {
    int framecount;
    int loop;
    int loop_frame;
    int frame_spd;
}animn_t;

typedef struct keys {
    sfKeyCode code;
    void (*fptr)(game_t *game);
}keyp_t;

typedef struct player_attack {
    int id;
    char *name;
    char *spritesheet;
    int type;
    int damage;
    int lingering_time;
    int cooldown;
    int frame;
    sfTime last_cast;
    sfIntRect hitbox;
    sfTexture *tex;
    sfSprite **spr;
    sfIntRect sprite_rect;
    sfKeyCode key;
    animn_t *anim_data;
}p_atk_t;

typedef struct player {
    char *name;
    char *spritesheet;
    int hp;
    int max_hp;
    int status;
    int frame;
    int facing;
    int jump_h;
    int jump_spd;
    int run_spd;
    int air_momentum;
    int atk_cd;
    int atk_id;
    int inflicted_damage;
    sfTime frame_time;
    sfTime status_time;
    sfTime pos_time;
    sfTime squat_time;
    sfTime atk_time;
    sfTime dmg_time;
    sfVector2f pos;
    sfVector2f speed;
    sfIntRect hurtbox;
    sfIntRect sprite_rect;
    sfMusic *hitsound;
    anim_e anim_s;
    animn_t **anim_data;
    p_atk_t **player_atk;
}player_t;

typedef struct entity_list {
    int id;
    char *name;
    int hp;
    int damage;
    int type;
    int behaviour;
    int run_spd;
    animn_t **anim_data;
    char *spritesheet;
    sfIntRect hurtbox;
    sfIntRect hitbox;
    sfIntRect sprite_rect;
}e_list_t;

typedef struct entity_map_data {
    int status;
    int id;
    sfVector2f pos;
}e_map_t;

typedef struct obstacle_map_data {
    int type;
    sfIntRect rect;
    char *spritesheet;
    sfSprite *sprite;
}o_map_t;

typedef struct map_data {
    sfVector2f size;
    sfVector2f starting_pos;
    int type;
    int parallax;
    e_map_t **e_map;
    o_map_t **o_map;
    char **spritesheet;
    sfMusic *music;
}map_t;

typedef struct texture {
    sfTexture *player;
    sfTexture **player_atk;
    sfTexture **entity;
    sfTexture **background;
}tex_t;

typedef struct sprite {
    sfSprite ***player;
    sfSprite ***player_atk;
    sfSprite ****entity;
    sfSprite **background;
}spr_t;

typedef struct game_over {
    char *bg_sprsh;
    char *ts_sprsh;
    char *retry_sprsh;
    sfIntRect ts_rect;
    sfIntRect retry_rect;
    sfTexture *ts_tex;
    sfTexture *bg_tex;
    sfTexture *retry_tex;
    sfSprite *ts_spr;
    sfSprite *bg_spr;
    sfSprite *retry_spr;
    sfMusic *music;
}game_over_t;

typedef struct hud {
    char *hud_sprsh;
    char *h_bar_sprsh;
    sfTexture *hud_tex;
    sfTexture *h_bar_tex;
    sfSprite *hud_spr;
    sfSprite *h_bar_spr;
    sfVector2f position;
}hud_t;

typedef struct title_screen {
    char *bg_sprsh;
    char *quit_sprsh;
    char *start_sprsh;
    sfTexture *bg_tex;
    sfTexture *quit_tex;
    sfTexture *start_tex;
    sfSprite *bg_spr;
    sfSprite *quit_spr;
    sfSprite *start_spr;
    sfIntRect start_rect;
    sfIntRect quit_rect;
    sfMusic *music;
}ts_t;

typedef struct end_screen {
    char *bg_sprsh;
    char *ts_sprsh;
    char *retry_sprsh;
    sfTexture *bg_tex;
    sfTexture *ts_tex;
    sfTexture *retry_tex;
    sfSprite *bg_spr;
    sfSprite *ts_spr;
    sfSprite *retry_spr;
    sfIntRect retry_rect;
    sfIntRect ts_rect;
    sfMusic *music;
}end_t;

typedef struct game {
    menu_e game_status;
    e_list_t **e_list;
    map_t *map;
    tex_t *tex;
    spr_t *spr;
    player_t *player;
    obj_t **obj;
    keyp_t **key;
    hud_t *hud;
    ts_t *title_screen;
    end_t *end_screen;
    sfClock *clock;
    sfTime time;
    sfVector2f cursor_pos;
    int mouse_click;
    sfRenderWindow *window;
    sfVideoMode mode;
    game_over_t *game_over;
}game_t;

/************ GAME LOAD ***************/

game_t *game_load(char *dirpath);
game_over_t *game_over_load(void);
ts_t *title_screen_load(void);
e_list_t **e_list_load(void);
player_t *player_load(void);
animn_t **anim_data_load(char **file);
animn_t **e_anim_data_load(char **file);
p_atk_t **player_attack_load(void);
tex_t *texture_load(game_t *game);
sfSprite ***player_spr_load(game_t *game);
spr_t *sprite_load(game_t *game);
e_map_t **load_entity_map(void);
o_map_t **load_obstacle_map(char *map);
map_t *map_load(char *map);
hud_t *hud_load(void);
sfVideoMode vmode_init(int w, int h, int bpp);
end_t *end_screen_load(void);

/************ LOAD UTIL ***************/

char *file_load(char *filepath);
char *copy_until(char **str, char c);
int char_to_int(char *str);
int get_ret_count(char *str);
sfIntRect extract_rect(char *str);
sfVector2f extract_vect(char *str);
animn_t *extract_anim_node(char *str);
char *run_strcat(char *str1, char *str2);
sfSprite *sprite_create(sfTexture *tex, sfIntRect *rect);
sfSprite *sprite_create_from_file(char *path);
sfSprite **sprite_array_load(sfTexture *tex, sfIntRect rect, int amnt, int h);
keyp_t **key_load(void);
keyp_t *key_init(sfKeyCode code, void (*fptr)(game_t *game));

/******** PRINT DATA (DEBUG) **********/

void print_entity_list(game_t *game);
void print_player(game_t *game);
void print_player_atk(game_t *game);
void print_map_data(game_t *game);

/************** MISC. *****************/

void draw_sprite(game_t *game, sfSprite *spr, sfVector2f pos);
int is_in_loading_range(game_t *game, int x);
int get_array_size(void **array);
void cat_help(void);

/************* GAME LOOP **************/

int global_parameter_init(game_t *game);
int game_status_selector(game_t *game);
int game_loop(game_t *game);
int player_data_init(game_t *game);
int death_screen(game_t *game);
int title_screen(game_t *game);
int end_screen(game_t *game);

/********** EVENT MANAGEMENT **********/

int key_press_management(game_t *game, sfKeyEvent key);
int event_management(game_t *game);
int death_screen_click_button(game_t *game);
int title_screen_click_button(game_t *game);
int end_screen_click_button(game_t *game);

/************ PLAYER DATA *************/

int player_data_update(game_t *game);
int player_frame_update(game_t *game);
int player_status_update(game_t *game);
int player_key_press_update(game_t *game);
int player_pos_update(game_t *game);
int player_move_dmg(game_t *game);
int player_height_update(game_t *game);
int player_attack_management(game_t *game, p_atk_t *p_atk);
int player_move(game_t *game, sfVector2f pos);
int player_attack_hit_management(game_t *game);
int player_hit_update(game_t *game, obj_t *obj);
int player_hit_management(game_t *game);
int can_player_move(game_t *game, sfVector2f pos);
void jump_management(game_t *game);

/********* DISPLAY MANAGEMENT *********/

int display_management(game_t *game);
int display_obstacles(game_t *game);
int display_obj(game_t *game);
int display_obj_setcolor(game_t *game, obj_t *obj);
int display_player(game_t *game);
int display_player_atk(game_t *game);
int display_player_setcolor(game_t *game);
int display_background(game_t *game);
int double_draw(game_t *game, int i, sfVector2f p_pos);
int display_layout(game_t *game);
int display_hud(game_t *game);
int death_screen_display(game_t *game);
int title_screen_display(game_t *game);
int end_screen_display(game_t *game);

/************* KEY PRESS **************/

void no_key(game_t *game);
void key_left(game_t *game);
void key_right(game_t *game);
void key_down(game_t *game);

/************* COLLISIONS *************/

int pos_in_rect_check(sfVector2f vect, sfIntRect rect);
int can_player_fall(game_t *game);
int rect_collide_check(sfIntRect rect1, sfIntRect rect2);

/************ OBJ MANAGMENT ***********/

int obj_init(game_t *game);
int obj_create(game_t *game, int id, e_map_t *mapdata);
int obj_data_update(game_t *game);
int obj_frame_update(game_t *game, obj_t *obj);
int obj_status_update(game_t *game, obj_t *obj);
int obj_hit_management(game_t *game, obj_t *obj);
int e_list_management(game_t *game);
int obj_move(game_t *game, obj_t *obj, sfVector2f pos);
int can_obj_fall(game_t *game, obj_t *obj);
int can_obj_move(game_t * game, obj_t *obj, sfVector2f pos);
int obj_behaviour_selector(game_t *game, obj_t *obj);
int behaviour_one_management(game_t *game, obj_t *obj);
int bhv_one_pos_update(game_t *game, obj_t *obj);
int bhv_one_height_update(game_t *game, obj_t *obj);
int behaviour_two_management(game_t *game, obj_t *obj);
int bhv_two_height_update(game_t *game, obj_t *obj);
int bhv_two_pos_update(game_t *game, obj_t *obj);
int bhv_two_facing_update(game_t *game, obj_t *obj);

/**************************************/



/**************************************/



/**************************************/



/**************************************/
#endif
