##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## 
##

SRC 	=	grep.c

OBJ	=	$(SRC:.c=.o)

NAME	=	grep

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) *.c -I./../include -L./../lib/my -lmy

clean:
	rm -f *~

fclean:
	rm -f *~
	rm -f $(NAME)

re: 	fclean all

test_run:
	gcc -o unit_tests $(NAME) ../tests/test_cat.c --coverage -lcriterion -I./../include -L./../lib/my -lmy
