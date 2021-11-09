/*
** EPITECH PROJECT, 2019
** my_hunter header
** File description:
** 
*/

#ifndef MY_HUNTER
#define MY_HUNTER

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>

/************ DEFINES *****************/

#define TIME get_time(game->clock) / 1000
#define AR game->ar
#define OD game->od
#define DUCK_I game->duck[i]
#define DUCK_TC duck->time_code
#define BPM game->bpm
#define BPM_OFFSET game->bpm_offset
#define PLAYER game->player_data
#define IMG game->img
#define TEX game->tex
#define SPR game->spr
#define CURSOR_POS game->cursor_pos
#define FRAMEBUFFER game->framebuffer
#define PIXARRAY game->framebuffer->pixarray
#define XOFF ((game->mode->width - 1200) / 2)
#define YOFF ((game->mode->height - 640) / 2)
#define DEC(value) ((value) - 48)
#define WINDOW game->window
#define MYHUNGREEN sf_color_init(90, 111, 117, 255)
#define MYHUNPURPLE sf_color_init(119, 95, 139, 255)
#define MYHUNDGREEN sf_color_init(69, 86, 90, 255)
#define MYHUNDPURPLE sf_color_init(96, 75, 113, 255)
#define VMODE game->mode

/************* STRUCTS ****************/

typedef struct framebuffer
{
    sfUint8 *pixarray;
    int width;
    int height;
} framebuffer_t;

typedef struct images {
    sfImage *duck_img;
    sfImage *appr_img;
    sfImage *hit300;
    sfImage *hit100;
    sfImage *hit50;
    sfImage *hitmiss;
    sfImage *background;
    sfImage *nb_sheet;
    sfImage *cursor;
} img_t;

typedef struct textures {
    sfTexture *duck_tex;
    sfTexture *appr_tex;
    sfTexture *hit300;
    sfTexture *hit100;
    sfTexture *hit50;
    sfTexture *hitmiss;
    sfTexture *background;
    sfTexture *framebuf;
    sfTexture **number;
    sfTexture *cursor;
} tex_t;

typedef struct sprites {
    sfSprite *hit300;
    sfSprite *hit100;
    sfSprite *hit50;
    sfSprite *hitmiss;
    sfSprite **number;
    sfSprite *cursor;
} spr_t;

typedef struct animation {
    sfVector2f pos;
    sfVector2f speed;
} anim_t;

typedef struct duck {
    anim_t *anim_data;
    sfVector2f die_pos;
    sfTexture *score_tex;
    int status;
    int time_code;
    int scored;
    char slot[2];
    int speed;
} duck_t;

typedef struct sound {
    sfMusic *music;
    sfMusic *hitsound;
} sound_t;

typedef struct player {
    int combo;
    int max_combo;
    int score;
    float accuracy;
    int zero_c;
    int fifty_c;
    int hundred_c;
    int thundred_c;
} player_t;

typedef struct game {
    duck_t *duck;
    img_t *img;
    tex_t *tex;
    spr_t *spr;
    sound_t *sound;
    player_t *player_data;
    framebuffer_t *framebuffer;
    sfClock *clock;
    sfRenderWindow *window;
    sfVideoMode *mode;
    sfVector2f cursor_pos;
    int status;
    int duck_amnt;
    int bpm;
    int bpm_offset;
    int ar;
    int od;
} game_t;

/********** GAME LOAD *****************/

game_t *load_game(char *folder);
duck_t *load_ducks(game_t *game, char *str);
img_t *load_images(void);
tex_t *load_tex(game_t *game);
spr_t *load_sprites(game_t *game);
sound_t *load_sounds(char *folder);
framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
int syntax_check(int argc, char **argv);

/*********** GAME UNLOAD ***************/

void unload_ducks(duck_t *duck);
void unload_images(img_t *img);
void unload_tex(tex_t *tex);
void unload_sprites(spr_t *spr);
void unload_sounds(sound_t *sound);
void unload_game(game_t *game);

/********** DATA DISPLAY **************/

int put_game_data(game_t *game);

/************* MISC. ******************/

char *copy_until(char *str, char c);
int char_to_int(char *str);
int get_ret_count(char *str);
long get_time(sfClock *clock);
sfVector2f sf_vector_init(float x, float y);
sfColor sf_color_init(int r, int g, int b, int a);
sfIntRect sf_rect_init(int left, int top, int width, int height);
char *sp_cat(char *str1, char *str2, char *str3);
sfSprite *sprite_create(sfTexture *tex);
sfRectangleShape *sf_rectshape_init(sfIntRect rect, sfColor color);
void sf_draw_sprite(game_t *game, sfSprite *sprite, sfVector2f vect);
int display_accuracy_chara_selector(char *acc, int i, int *j);

/************ GAME ********************/

int start_game(game_t *game);
int event_management(game_t *game);
int duck_die_refresh(game_t *game);

/************ WIN RENDERING ***********/

int display_management(game_t *game);
int display_duck(game_t *game, duck_t *duck);
int floating_scores_management(game_t *game);
int display_score(game_t *game);
int display_accuracy(game_t *game);
int display_combo(game_t *game);
void display_borders(game_t *game);
void my_putpixel(game_t *game, sfVector2f vect, sfColor color);
void draw_rect(game_t *game, sfIntRect rect, sfColor color);
void draw_border_rects(game_t *game);
void draw_filled_rect(game_t *game, sfIntRect rect, sfColor color);
void framebuffer_clear(game_t *game);
void display_result_screen(game_t *game);
void display_cursor(game_t *game);
void rs_draw_score(game_t *game);
void rs_draw_max_combo(game_t *game);
void rs_draw_accuracy(game_t *game);
void rs_draw_thundred(game_t *game);
void rs_draw_hundred(game_t *game);
void rs_draw_fifty(game_t *game);
void rs_draw_miss(game_t *game);

/*************************************/

#endif
