##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## 
##

SRC 	=	src/load_cmd.c		\
		src/load_env.c		\
		src/load_path.c		\
		src/load_shell.c	\
		src/main.c		\
		src/misc.c		\
		src/misc2.c		\
		src/shell_cd.c		\
		src/shell_cmd.c		\
		src/shell_env.c		\
		src/shell_exec.c	\
		src/shell_exit.c	\
		src/shell_prompt.c	\
		src/shell_setenv.c	\
		src/shell_unsetenv.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -I./include -g

LDFLAGS	=	-L./lib/my -lmy

NAME	=	mysh

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
