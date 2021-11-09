##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRCDIR  =       ./src/

SRC	=	$(SRCDIR)main.c		\
		$(SRCDIR)get_next_line.c	\
		$(SRCDIR)my_array.c	\
		$(SRCDIR)turn.c	\
		$(SRCDIR)speed.c	\
		$(SRCDIR)verif.c	\

NAME	=	ai

all :	$(NAME)

$(NAME) :
	make -C lib/my
	gcc -o $(NAME) -Wall -Wextra -g $(SRC) -I./include -L./lib/my -lmy

clean :
	make clean -C lib/my
	rm -f ~* \#*\#

fclean :	clean
	rm -f $(NAME)
	make fclean -C lib/my

re :	fclean all
