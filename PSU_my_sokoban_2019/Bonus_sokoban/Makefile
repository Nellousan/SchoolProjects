##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## 
##

SRC 	=	src/main.c	\
		src/game_load.c	\
		src/game_unload.c	\
		src/misc.c		\
		src/misc2.c		\
		src/map_load.c	\
		src/game.c		\
		src/images_load.c	\
		src/sf_display_management.c	\
		src/display_management.c	\
		src/event_management.c	\
		src/game_over_check.c	\
		src/player_movement.c	\
		src/box_status_refresh.c	\

NAME	=	my_sokoban

all:	$(NAME)

$(NAME):
	$(MAKE) -C./lib/my
	gcc -o $(NAME) $(SRC) -I./include -L./lib/my -lmy -lncurses -l csfml-graphics -l csfml-system -Wall -Wextra -Wswitch -g

clean:
	rm -f *~

fclean:
	rm -f *~
	rm -f $(NAME)

re: 	fclean all
