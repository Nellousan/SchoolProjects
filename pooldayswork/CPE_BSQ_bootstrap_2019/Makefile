##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## 
##

SRC 	=	#SRC

NAME	=	#NAME

all:	$(NAME)

$(NAME):
	$(MAKE) -C./lib/my
	gcc -o $(NAME) $(SRC) -I./include -L./lib/my -lmy -Wall -Wextra

clean:
	rm -f *~

fclean:
	rm -f *~
	rm -f $(NAME)

re: 	fclean all
