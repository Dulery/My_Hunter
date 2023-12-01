##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC = my_putchar.c \
      my_isneg.c \
      my_put_nbr.c \
      my_swap.c \
      my_putstr.c \
      my_strlen.c \
      my_getnbr.c \
      my_sort_int_array.c \
      my_compute_power_rec.c \
      my_compute_square_root.c \
      my_is_prime.c \
      my_find_prime_sup.c \
      my_strcpy.c \
      my_strncpy.c \
      my_revstr.c \
      my_strstr.c \
      my_strcmp.c \
      my_strncmp.c \
      my_strupcase.c \
      my_strlowcase.c \
      my_strcapitalize.c \
      my_str_isalpha.c \
      my_str_isnum.c \
      my_str_islower.c \
      my_str_isupper.c \
      my_str_isprintable.c \
      my_showstr.c \
      my_showmem.c \
      my_strcat.c \
      my_strncat.c \
      my_putnbr_hexa.c \
      my_flags.c \
      my_flags2.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra

NAME = libmy.a

all: cpylib cpyh

$(NAME): $(OBJ)
	cp my.h ../../include
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../

$(OBJ): $(SRC)
	gcc -c $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

auteur:
	echo $(USER) > auteur

cpylib: $(NAME)
	cp $(NAME) ..

cpyh:
	cp $(NAME) ../..include
