##
## EPITECH PROJECT, 2019
## Makefile libmy
## File description:
## 
##

SRC 	=	my_compute_power_rec.c	\
		my_compute_square_root.c\
		my_malloc.c		\
		my_putchar.c		\
		my_put_nbr.c		\
		my_putstr.c		\
		my_showstr.c		\
		my_show_word_array.c	\
		my_strcat.c		\
		my_strcmp.c		\
		my_strcpy.c		\
		my_strdup.c		\
		my_strlen.c		\
		my_strncat.c		\
		my_strncmp.c		\
		my_strncpy.c		\
		my_str_to_word_array.c	\
		my_swap.c		\

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
