##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## 
##

SRC 	=	src/main.c		\
		src/game_load.c		\
		src/game_over_load.c	\
		src/end_screen_load.c	\
		src/load_title_screen.c	\
		src/load_entity_list.c	\
		src/load_player_data.c	\
		src/load_util.c		\
		src/load_util2.c	\
		src/load_map.c		\
		src/load_textures.c	\
		src/load_sprites.c	\
		src/load_hud.c		\
		src/misc.c		\
		src/print_data.c	\
		src/game_status_selector.c	\
		src/game.c		\
		src/death_screen.c	\
		src/title_screen.c	\
		src/end_screen.c	\
		src/display_management.c\
		src/display_background.c\
		src/display_player.c	\
		src/display_obj.c	\
		src/event_management.c	\
		src/player_data_update.c\
		src/player_key_press_update.c	\
		src/player_attack_management.c	\
		src/player_position_update.c	\
		src/player_hit_management.c	\
		src/key_press.c		\
		src/init_game.c		\
		src/collision_check.c	\
		src/player_movement.c	\
		src/obj_management.c	\
		src/obj_data_update.c	\
		src/obj_movement.c	\
		src/obj_behaviour_selector.c	\
		src/obj_behaviour_one.c		\
		src/obj_behaviour_two.c 	\
		src/entity_list_management.c	\

OBJ     =       $(SRC:.c=.o)

LDFLAGS =       -L./lib/my -lmy -lm -l csfml-graphics -l csfml-audio -l csfml-window -l csfml-system

NAME	=	my_runner

CFLAGS  =       -Wall -Wextra -I./include -g

all:    $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C./lib/my
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(MAKE) clean -C./lib/my
	rm -f *~
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C./lib/my
	rm -f $(NAME)

re:     fclean all
