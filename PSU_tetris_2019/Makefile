##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## 
##

SRCDIR	=	src

SRC 	=	$(SRCDIR)/main.c		\
		$(SRCDIR)/debug.c		\
		$(SRCDIR)/display_board.c	\
		$(SRCDIR)/display_management.c	\
		$(SRCDIR)/game.c		\
		$(SRCDIR)/load_game.c		\
		$(SRCDIR)/load_options.c	\
		$(SRCDIR)/map_node_init.c	\
		$(SRCDIR)/misc.c		\
		$(SRCDIR)/tetriminosdir.c	\
		$(SRCDIR)/load_tetriminos.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -I./include -g

LDFLAGS	=	-L./lib -lmy -lncurses

NAME	=	tetris

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
