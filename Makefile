##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## oui
##

NAME 	= 	my_hunter

SRC 	= 	src/my_main.c		\
                src/game/game_view.c	\

OBJ 	= 	$(SRC:.c=.o)

CFLAGS 	= 	-Wall -Wextra

CSFML 	= 	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

all: 	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(CSFML)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
