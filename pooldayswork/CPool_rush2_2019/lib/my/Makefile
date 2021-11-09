##
## EPITECH PROJECT, 2019
## Makefile libmy
## File description:
## 
##

SRC 	=	count_letters.c	\
		frequencies.c	\
		y_putchar.c	\
		my_put_nbr.c	\
		my_putstr.c	\
		putpercent.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp libmy.a ../
	cp my.h ../../include/
clean:
	rm -f *.o

fclean:
	rm -f *.o
	rm -f $(NAME)

re: fclean all
