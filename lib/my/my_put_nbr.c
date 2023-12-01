/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** number given should be print as a strin/char
*/

#include "my.h"

static int print_nb(int int_nb_3, char *nb_list_2)
{
    int k = 0;

    for (k = int_nb_3; k > 0; k--) {
        my_putchar(nb_list_2[k - 1]);
    }
    return 0;
}

static int set_list_nb(int nb_2, int int_nb_2)
{
    char nb_list[int_nb_2];
    int j = 0;
    int figure_temp = nb_2;

    for (j = 0; j < int_nb_2; j++) {
        nb_list[j] = 48 + (figure_temp % 10);
        figure_temp = (figure_temp - (figure_temp % 10)) / 10;
    }
    print_nb(int_nb_2, nb_list);
    return 0;
}

static int print_maximum(void)
{
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
    return 0;
}

int my_put_nbr(int nb)
{
    int int_nb = 1;
    int temp_nb = nb;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    while ((temp_nb / 10) != 0) {
        int_nb = int_nb + 1;
        temp_nb = temp_nb / 10;
    }
    if (nb == -2147483648) {
        print_maximum();
    } else {
        set_list_nb(nb, int_nb);
    }
    return 0;
}
