##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## oui
##

CC	=	gcc

SRC	=	./src/main.c \
		./src/pointeur.c \
		./src/my_make_window.c \
		./src/zombies.c \
		./src/fusil.c \
		./src/my_create.c \
		./src/coeur.c \
		./src/lib_bis.c \
		./src/menu.c	\
		./src/pause.c

OBJ	=	$(SRC:.c=.o)

NAME =	my_hunter

FLAGS	=	-W \
			-Wextra \
			-Werror \
			-Wall \
			-lcsfml-graphics \
			-lcsfml-audio \
			-lcsfml-window \
			-lcsfml-system \

RM = rm -rf

all:
		$(CC) $(SRC) $(FLAGS) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re: 		fclean all
