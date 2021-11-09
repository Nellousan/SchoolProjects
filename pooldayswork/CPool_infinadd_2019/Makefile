##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## 
##

SRC 	=	main.c		\
		infinadd.c	\


NAME	=	infin_add

all:	$(NAME)

$(NAME):
	$(MAKE) -C./lib/my
	gcc -g -o $(NAME) $(SRC) -I./include -L./lib/my -lmy

clean:
	rm -f *~

fclean:
	rm -f *~
	rm -f $(NAME)

re: 	fclean all
