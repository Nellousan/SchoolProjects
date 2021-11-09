##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## 
##

SRC 	=	main.c		\

NAME	=	eval_expr

all:	$(NAME)

$(NAME):
	$(MAKE) -C./lib/my
	gcc -o $(NAME) $(SRC) -I./include -L./lib/my -lmy

clean:
	rm -f *~

fclean:
	rm -f *~
	rm -f $(NAME)

re: 	fclean all
