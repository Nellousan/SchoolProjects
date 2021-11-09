##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## 
##

SRC 	=	main.c 		\
		list_init.c	\
		misc.c		\
		queue_op.c	\
		list_sort.c	\

NAME	=	push_swap

all:	$(NAME)

$(NAME):
	$(MAKE) -C./lib/my
	gcc -o $(NAME) $(SRC) -I./include -L./lib/my -lmy -Wall -Wextra -g

clean:
	rm -f *~

fclean:
	rm -f *~
	rm -f $(NAME)

re: 	fclean all
