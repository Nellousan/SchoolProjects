##
## EPITECH PROJECT, 2019
## Makefile libmy
## File description:
## 
##

SRC 	=	nb_occurences.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	rush2

all:	$(NAME)

$(NAME):
	gcc nb_occurences.c -o $(NAME) -I./lib/my -L./lib/my -lmy
clean:
	rm -f *.o

fclean:
	rm -f *.o
	rm -f $(NAME)

re: fclean all
