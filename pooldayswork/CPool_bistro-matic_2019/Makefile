##
## EPITECH PROJECT, 2019
## Makefile
## File description:
##
##

SRC	=	main.c		\
		infinops.c	\
		send_ops.c	\
		misc.c		\
		misc_two.c	\
		convert_base.c	\
		syntax_check.c	\
		bistro.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	calc

CFLAG	=	-I./include -Wall -Wextra

all:
	$(MAKE) -C ./lib/my/
	gcc -o $(NAME) $(SRC) -L./lib/my -lmy -I./include -Wextra -Wall -g

clean:
	rm -f *~

fclean:	clean
	rm -f $(NAME)

re:	fclean all
