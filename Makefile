##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## compile libmy
##

SRC = 	src/main.c	\
	src/init_struct.c	\
	src/nbrlen.c	\
	src/next_move.c	\
	src/print_grid.c	\
	src/is_winner.c

OBJ := $(SRC:%.c=%.o)

NAME := tictactoe

CFLAGS := -W -Wall -Wextra -Werror

INC := -I./include

all:$(NAME)

$(NAME): $(OBJ)
	@gcc -o $@ $^ $(CFLAGS) $(INC)

%.o: %.c
	@gcc -c $< -o $@ $(CFLAGS) $(INC)

tests_run: fclean
	cd tests && make all && cd ..

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(BUILD_DIR)
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

.NOTPARALLEL:

re: fclean all

.PHONY: all, tests_run, clean, fclean, re
