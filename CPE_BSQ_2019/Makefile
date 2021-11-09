##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## 
##

SRC 	=	main.c		\
		bsq_bis.c		\
		misc.c		\
		map.c		\
		inits.c		\
		special_cases.c	\

NAME	=	bsq

all:	$(NAME)

$(NAME):
	$(MAKE) -C./lib/my
	gcc -o $(NAME) $(SRC) -I./include -L./lib/my -lmy -Wall -Wextra -l csfml-graphics -g

clean:
	rm -f *~

fclean:
	rm -f *~
	rm -f $(NAME)

re: 	fclean all
