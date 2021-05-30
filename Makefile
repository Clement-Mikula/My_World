##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##


CFLAGS		=	-I include -L lib/my -lmy -Wall -Wextra -g3

CTEST = --coverage -lcriterion

SRC =	main.c	\
		src/button.c	\
		src/animations.c	\
		src/line.c	\
		src/map.c	\
		src/initialisation.c	\
		src/events.c	\
		src/game_help.c	\
		src/game_loop.c

OBJ	=	$(SRC:.c=.o)

SRC_RUN_TEST =  tests/tests.c

NAME =	my_world

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -I ./include	-l csfml-system -l csfml-window -l csfml-graphics -l csfml-audio -l csfml-network -g3\

cleantest:
	rm -f *.gcno
	rm -f *.gcda
	rm -f unit_tests

clean:
	rm -f $(OBJ)

fclean: clean cleantest
	rm -f $(NAME)

unit_tests:
	gcc -o unit_tests $(SRC) $(SRC_RUN_TEST) $(CTEST) -I./include -L ./lib/my -lmy

tests_run: unit_tests
	./unit_tests
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches
	gcovr -r .
	gcovr -r . --branches

re: fclean all

.PHONY: all clean fclean re