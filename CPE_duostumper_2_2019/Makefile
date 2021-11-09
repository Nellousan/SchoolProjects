##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## 
##

SRCDIR 	=	src

SRC 	=	$(SRCDIR)/main.c		\
		$(SRCDIR)/load_game.c		\
		$(SRCDIR)/game.c		\
		$(SRCDIR)/game_over_check.c	\
		$(SRCDIR)/game_over_check_util.c\
		$(SRCDIR)/display_board.c	\
		$(SRCDIR)/tab.c			\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -I./include -g

LDFLAGS	=	-L./lib/my -lmy

NAME	=	connect4

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
