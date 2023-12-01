/*
** EPITECH PROJECT, 2023
** my_isneg
** File description:
** negative, or positive ?
*/

#include "my.h"

int my_isneg(int n)
{
    if (n >= 0)
        my_putchar('P');
    else
        my_putchar('N');
}
