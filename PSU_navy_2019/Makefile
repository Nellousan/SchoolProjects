##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## 
##

SRC 	=	src/main.c			\
		src/game_load.c			\
		src/boats_placing.c		\
		src/boats_loading.c		\
		src/set_boats.c			\
		src/load_util.c			\
		src/display_map.c		\
		src/misc.c			\
		src/connection.c		\
		src/turn_attack.c		\
		src/turn_wait.c			\
		src/game.c			\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -I./include

LDFLAGS	=	-L./lib/my -lmy

NAME	=	navy

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
