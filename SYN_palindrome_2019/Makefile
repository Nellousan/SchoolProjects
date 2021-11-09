##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## 
##

OSRC	=	src/misc.c		\
		src/get_opts.c          \
		src/turnover.c          \
		src/base_convert.c      \
		src/display_help.c      \

SRC 	=	src/main.c		\
		$(OSRC)			\

TESTSRC = 	tests/test_base.c	\
		tests/test_turnover.c	\
		$(OSRC)			\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -I./include -g

LDFLAGS	=	-L./lib/my -lmy

NAME	=	palindrome

all:	$(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C./lib/my
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

tests_run:
	$(MAKE) -C./lib/my
	gcc -o unit_tests $(TESTSRC) $(CFLAGS) $(LDFLAGS) -lcriterion --coverage
	./unit_tests --verbose
	rm unit_tests
	rm *.gcda *.gcno

clean:
	$(MAKE) clean -C./lib/my
	rm -f *~
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C./lib/my
	rm -f $(NAME)

re: 	fclean all
