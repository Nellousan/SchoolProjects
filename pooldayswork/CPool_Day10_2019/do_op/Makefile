##
## EPITECH PROJECT, 2019
## Makefile libmy
## File description:
## 
##

SRC 	=	main .c			\
		my_compute_power_rec.c	\
		my_operations.c		\
		my_putchar.c		\
		my_put_nbr.c		\
		my_putstr.c		\
		my_strlen.c		\


NAME	=	do-op

all:	$(NAME)

$(NAME):
	gcc *.c -o $(NAME)
clean:
	rm -f *.o

fclean:
	rm -f *.o
	rm -f $(NAME)

re: fclean all
