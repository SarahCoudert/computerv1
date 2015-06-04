FLAGS=-Wall -Wextra -Werror

DEBUG =$(CFLAGS) -g

NAME=computor

CC=gcc

SRC=main.c parsing.c ft_atof.c math.c calculus.c

INC=libft/includes

OBJ=$(SRC:.c=.o)

RM=rm -f

.PHONY: all, clean, fclean, re

all:
	@make $(NAME)

$(NAME): $(SRC)
	@make -C libft/
	@echo "\033[32mCompile all \".c\"\033[0m"
	@$(CC) $(CFLAGS) -c $(SRC) -I $(INC)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a
	@echo "\033[36mCreate $(NAME)\033[0m"

clean:
	@make -C libft/ clean
	@echo "\033[31mDelete all \".o\" in $(NAME)\033[0m"
	@$(RM) $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@echo "\033[31mDelete $(NAME) executable\033[0m"
	@$(RM) $(NAME)

re: fclean all

debug:
	@make -C libft/ fclean
	@make -C libft/ debug
	@echo "\033[32mCompile all \".c\" with debug flag\033[0m"
	@$(CC) $(DEBUG) -c $(SRC) -I $(INC)
	@$(CC) $(DEBUG) -o $(NAME) $(OBJ) libft/libft.a
	@echo "\033[36mCreate $(NAME) with debug flag\033[0m"
