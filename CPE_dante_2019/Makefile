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

all:
	$(MAKE) -C./lib/my
	$(MAKE) -C./generator
	$(MAKE) -C./solver

clean:
	$(MAKE) clean -C./lib/my
	$(MAKE) clean -C./generator
	$(MAKE) clean -C./solver
	rm -f *~
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C./lib/my
	$(MAKE) fclean -C./generator
	$(MAKE) fclean -C./solver
	rm -f $(NAME)

re: 	fclean all
