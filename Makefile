##
## EPITECH PROJECT, 2022
## B-PSU-200-LYN-2-1-minishell2-theo.alibert
## File description:
## Makefile
##


SRC     =      src/main.c

CFLAGS  =       -I./include -L./lib -lmy -g3 -Wall -Wextra

OBJ     =       $(SRC:.c=.o)

NAME    =       mysh

all:    $(NAME)

$(NAME): $(OBJ)
	make -C ./lib/my --no-print-directory
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	make -C ./lib/my clean
	rm -f $(OBJ)

fclean: clean
	make -C ./lib/my fclean
	rm -f $(NAME)

re: fclean all
