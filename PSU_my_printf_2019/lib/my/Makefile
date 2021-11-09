##
## EPITECH PROJECT, 2019
## Makefile libmy
## File description:
## 
##

SRC 	=	auto_malloc.c		\
		my_array.c		\
		my_compute_power_rec.c	\
		my_compute_square_root.c\
		my_convert_base.c	\
		my_convert_base_misc.c	\
		my_putchar.c		\
		my_put_nbr.c		\
		my_putstr.c		\
		my_printf.c		\
		my_printf_flag_func.c	\
		my_printf_flag_func2.c	\
		my_printf_flag_func3.c	\
		my_printf_int_redirect.c\
		my_revstrdup.c		\
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
		my_swap.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp libmy.a ../
	cp libmy.a ../../
	cp my.h ../../include/
clean:
	rm -f *.o

fclean:
	rm -f *.o
	rm -f $(NAME)
	rm -f ../$(NAME)

re: fclean all
