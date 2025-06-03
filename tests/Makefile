##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC = 	../src/error_handling.c

SRC_TESTS = test_error_handling.c

OBJ = $(SRC:.c=.o)

NAME = unit_tests

CRIT = -lcriterion --coverage

INC = -I../include

all:
	gcc -o $(NAME) $(SRC) $(SRC_TESTS) $(CRIT) $(INC)
	./$(NAME)
	gcovr --exclude ./$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)
	find -type f -name '*~' -delete
	find -type f -name '#*#' -delete
	find -type f -name '*.o' -delete
	find -type f -name 'libmy.a' -delete
	find -type f -name 'coding-style-reports.log' -delete
	find -type f -name '*.gcno' -delete
	find -type f -name '*.gcda' -delete
	find -type f -name 'unit_tests' -delete

re: fclean all
