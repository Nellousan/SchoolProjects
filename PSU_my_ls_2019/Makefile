##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## 
##

SRC 	=	src/main.c		\
		src/misc.c		\
		src/ls.c		\
		src/ls_sort_time.c	\
		src/ls_display.c	\
		src/ls_line.c		\
		src/ls_load.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -I./include -g

LDFLAGS	=	-L./lib/my -lmy

NAME	=	my_ls

all:	$(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C./lib/my
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(MAKE) clean -C./lib/my
	rm -f *~
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C./lib/my
	rm -f $(NAME)

re: 	fclean all
