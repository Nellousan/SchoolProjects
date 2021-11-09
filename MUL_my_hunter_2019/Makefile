##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## 
##

SRC 	=	src/main.c		\
		src/game_load.c	\
		src/ducks_load.c	\
		src/misc.c		\
		src/misc2.c		\
		src/game.c		\
		src/event_management.c	\
		src/display_management.c	\
		src/display_duck.c	\
		src/display_scores.c\
		src/display_borders.c	\
		src/images_load.c	\
		src/sound_load.c	\
		src/duck_hit_management.c	\
		src/beat_duck_textures.c	\
		src/framebuffer_draw.c	\
		src/result_screen.c	\
		src/result_screen_scores.c	\
		src/result_screen_scores2.c	\
		src/game_unload.c	\
		src/images_unload.c	\
		src/ducks_unload.c	\
		src/sound_unload.c	\
		src/syntax_check.c	\

NAME	=	my_hunter

all:	$(NAME)

$(NAME):
	$(MAKE) -C./lib/my
	gcc -o $(NAME) $(SRC) -I./include -L./lib/my -lmy -l csfml-graphics -l csfml-audio -l csfml-system -lm -Wall -Wextra -g

clean:
	rm -f *~

fclean:
	rm -f *~
	rm -f $(NAME)

re: 	fclean all
