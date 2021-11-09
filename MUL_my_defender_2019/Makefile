##
## EPITECH PROJECT, 2019
## Makefile
## File description:
##
##

SRCDIR	=	src/

SRC	=			\
		$(SRCDIR)/create_mob.c			\
		$(SRCDIR)/display_util.c		\
		$(SRCDIR)/event_management.c		\
		$(SRCDIR)/game.c			\
		$(SRCDIR)/game_display_management.c	\
		$(SRCDIR)/load_game.c			\
		$(SRCDIR)/load_map.c			\
		$(SRCDIR)/load_mob.c			\
		$(SRCDIR)/load_player.c			\
		$(SRCDIR)/load_sprite.c			\
		$(SRCDIR)/load_tower.c			\
		$(SRCDIR)/load_util.c			\
		$(SRCDIR)/main.c			\
		$(SRCDIR)/spr_load_util.c		\
		$(SRCDIR)/display_enemies.c		\
		$(SRCDIR)/move_mob.c			\
		$(SRCDIR)/tower_create.c		\
		$(SRCDIR)/tower_display.c		\
		$(SRCDIR)/tower_management.c		\
		$(SRCDIR)/reset_mob.c			\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -I./include -g

LDFLAGS	=	-L./lib/my -lmy -l csfml-graphics -l csfml-audio -l csfml-system -l csfml-window -lm

NAME	=	my_defender

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

re:	fclean all
