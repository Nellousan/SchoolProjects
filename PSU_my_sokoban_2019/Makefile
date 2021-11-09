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
		src/map_load.c	\
		src/game.c		\
		src/display_management.c	\
		src/event_management.c	\
		src/game_over_check.c	\
		src/player_movement.c	\
		src/box_status_refresh.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -I./include

LDFLAGS	=	-L./lib/my -lmy -lncurses

NAME	=	my_sokoban

all:	$(NAME)

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

re: 	fclean all
