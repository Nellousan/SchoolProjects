/*
** EPITECH PROJECT, 2020
** def
** File description:
** proto
*/

#ifndef DEF_PROTO
#define DEF_PROTO

game_t *game_load(void);
map_t *map_load(void);
player_t *player_load(void);
tower_t **tower_load(void);
mob_d_t **mob_load(void);
spr_t *sprite_load(game_t *game);
game_t *create_enemy(game_t *game);
void move_mob(game_t *game);

int game_loop(game_t *game);
int event_management(game_t *game);

char *file_load(char *filepath);
char *copy_until(char **str, char c);
int char_to_int(char *str);
int get_occurences(char *str, char c);

sfSprite *sprite_create_from_file(char *str, sfIntRect *rect);
sfSprite *sprite_create(sfTexture *tex, sfIntRect *rect);
sfSprite **load_sprite_array(char *str, sfIntRect r, int amnt);

int display_management(game_t *game);
void display_enemies(game_t *game);
int draw_sprite(game_t *game, sfSprite *spr, sfVector2f *pos);

int create_tower(game_t *game, int id, sfVector2f pos);
int display_towers(game_t *game);
int tower_management(game_t *game);
void reset_mob(game_t *game);

#endif
