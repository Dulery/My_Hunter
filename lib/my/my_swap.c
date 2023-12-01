/*
** EPITECH PROJECT, 2023
** my_swap
** File description:
** swapping content of two int, with adresses.
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
