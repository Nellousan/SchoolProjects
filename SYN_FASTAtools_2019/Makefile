##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## 
##

SRCDIR	=	src

SRC 	=	$(SRCDIR)/append.c	\
		$(SRCDIR)/get_fasta.c	\
		$(SRCDIR)/main.c	\
		$(SRCDIR)/misc.c	\
		$(SRCDIR)/options_b.c	\
		$(SRCDIR)/options_c.c	\
		$(SRCDIR)/options_d.c	\
		$(SRCDIR)/options_e.c	\
		$(SRCDIR)/options.c	\
		$(SRCDIR)/selector.c	\
		$(SRCDIR)/strcat.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -I./include -g

LDFLAGS	=	-L./lib/my -lmy

NAME	=	FASTAtools

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
