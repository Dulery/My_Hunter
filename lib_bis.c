/*
** EPITECH PROJECT, 2023
** libbis.c
** File description:
** oui
*/

#include "my.h"

void my_putchar(char c, int fd)
{
    write(fd, &c, 1);
}

int my_put_nbr(int nb, int fd)
{
    if (nb >= 10)
        my_put_nbr(nb / 10, fd);
    my_putchar((nb % 10) + 48, fd);
    return (0);
}

int my_getnbr(char const *str)
{
    int j = 0;
    int k = 1;
    int rtn = 0;

    while (str[j] >= 48 && str[j] <= 57)
        j++;
    j--;
    while (0 <= j) {
        rtn = rtn + (str[j] - 48) * k;
        k = k * 10;
        j--;
    }
    return (rtn);
}
