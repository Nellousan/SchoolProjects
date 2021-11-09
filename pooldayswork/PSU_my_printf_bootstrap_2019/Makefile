##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## 
##

SRC 	=	main.c		\
		stdarg.c	\

NAME	=	argtest

all:	$(NAME)

$(NAME):
	$(MAKE) -C./lib/my
	gcc -o $(NAME) $(SRC) -I./include -L./lib/my -lmy -Wall -Wextra

clean:
	rm -f *~

fclean:
	rm -f *~
	rm -f $(NAME)

re: 	fclean all

test:
	$(MAKE) -C./lib/my
	gcc -o unit_test unit_tests/stdarg_tests.c -I./include -L./lib/my -lmy -Wall -Wextra -lcriterion
	./unit_test
	rm unit_test
