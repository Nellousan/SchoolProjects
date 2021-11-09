##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## 
##

SRC 	=	main.c		\
		map.c		\
		chara.c		\
		chara_movement.c\

NAME	=	path

all:	$(NAME)

$(NAME):
	$(MAKE) -C./lib/my
	gcc -g -o $(NAME) $(SRC) -I./include -L./lib/my -lmy -l csfml-graphics

clean:
	rm -f *~

fclean:
	rm -f *~
	rm -f $(NAME)

re: 	fclean all
