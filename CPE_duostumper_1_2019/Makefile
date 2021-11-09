##
## EPITECH PROJECT, 2020
## CPE_duostumper_1_2019
## File description:
## Makefile
##

SRC_DIR		=	src/
INC_DIR		=	include/
LIB_DIR		=	lib/my/

SRC		=	$(SRC_DIR)main.c		\
			$(SRC_DIR)syntax_check.c	\
			$(SRC_DIR)word_array.c		\
			$(SRC_DIR)fractals.c		\
			$(SRC_DIR)my_putstr_error.c	\
			$(SRC_DIR)fill_2d_tab.c		\
			$(SRC_DIR)fractals_gen.c	\
			$(SRC_DIR)auto_malloc.c		\

OBJ		=	$(SRC:.c=.o)

NAME		=	fractals

CFLAGS		+=	-Wall -Wextra -Werror -I./include

LDLFLAGS	+=	-L $(LIB_DIR) -lmy

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C $(LIB_DIR)
		gcc -o $(NAME) $(OBJ) $(LDLFLAGS)

clean:
		@make clean -C $(LIB_DIR) --no-print-directory
		@rm -f $(OBJ)

fclean:		clean
		@make fclean -C $(LIB_DIR) --no-print-directory
		@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re run
