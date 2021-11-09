##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## 
##

SRCDIR	=	./src/

VSRCDIR	=	visualizer

SRC 	=	$(SRCDIR)main.c				\
		$(SRCDIR)get_next_line.c		\
		$(SRCDIR)open.c				\
		$(SRCDIR)error.c			\
		$(SRCDIR)display.c			\
		$(SRCDIR)verif.c			\
		$(SRCDIR)count.c			\
		$(SRCDIR)parse_anthill.c		\
		$(SRCDIR)misc.c				\
		$(SRCDIR)algo.c				\
		$(SRCDIR)init.c				\
		$(SRCDIR)info.c				\
		$(SRCDIR)ant_list_init.c		\
		$(SRCDIR)road.c				\
		$(SRCDIR)reverse.c                         \

VSRC 	=	#SRC

OBJ	=	$(SRC:.c=.o)

VOBJ	=	$(VSRC:.c=.o)

CFLAGS	=	-Wall -Wextra -I./include -g

LDFLAGS	=	-L./lib/my -lmy

NAME	=	lem_in

VNAME	=	visualizer

all:	$(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C./lib/my
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

$(VNAME): $(VOBJ)
	$(MAKE) -C./lib/my
	gcc -o $(VNAME) $(VOBJ) $(LDFLAGS)

clean:
	$(MAKE) clean -C./lib/my
	rm -f *~
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C./lib/my
	rm -f $(NAME)

re: 	fclean all
