##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## 
##

SRC 	=	main.c		\

NAME	=	a.out

all:	$(NAME)

$(NAME):
	$(MAKE) -C./lib/my
	gcc -o $(NAME) $(SRC) -g -I./include -L./lib/my -lmy -l csfml-graphics

clean:
	rm -f *~

fclean:
	rm -f *~
	rm -f $(NAME)

re: 	fclean all
