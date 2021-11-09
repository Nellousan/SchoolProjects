##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## 
##

SRC 	=	cat.c

OBJ	=	$(SRC:.c=.o)

NAME	=	cat

all:	$(NAME)

$(NAME):
	$(MAKE) -C./../lib/my
	gcc -o $(NAME) *.c -I./../include -L./../lib/my -lmy

clean:
	rm -f *~

fclean:
	rm -f *~
	rm -f $(NAME)

re: 	fclean all

test_run:
	gcc -o unit_tests cat.c ../tests/test_cat.c --coverage -lcriterion -I./../include -L./../lib/my -lmy
