/*
** EPITECH PROJECT, 2023
** libbis.c
** File description:
** oui
*/

#include "../my.h"

void my_putchar(char c, int fd)
{
    write(fd, &c, 1);
}

int my_put_nbr(int nombre, int nb2)
{
    if (nombre >= 10) {
        my_put_nbr(nombre / 10, nb2);
    }
    my_putchar((nombre % 10) + 48, nb2);
    return 0;
}

int my_getnbr(char const *str)
{
    int t = 0;
    int j = 0;
    int k = 1;

    while (str[j] >= 48 && str[j] <= 57)
        j++;
    j--;
    while (0 <= j) {
        t = t + (str[j] - 48) * k;
        k = k * 10;
        j--;
    }
    return t;
}

int my_putstr(char const *str)
{
    if (str == NULL) {
        return 0;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        the_putchar(str[i]);
    }
    return 0;
}

void the_putchar(char c)
{
    write(1, &c, 1);
}
