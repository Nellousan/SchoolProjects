##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## 
##

SRC 	=	#SRC

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -I./include

LDFLAGS	=	-L./lib/my -lmy

NAME	=	#NAME

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
