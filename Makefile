##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## my make file
##

CC	=	gcc

SRC	=	main.c \
		pointeur.c \
		my_draw_window.c \
		zombies.c \
		fusil.c \
		my_create.c \
		coeur.c \
		score.c \
		menu.c	\
		pause.c

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
