/*
** EPITECH PROJECT, 2023
** my_compute_factorial_rec
** File description:
** factorial but using recursivity
*/

#include "my.h"

int my_compute_factorial_rec(int nb)
{
    int result;

    if (nb < 0
        || nb > 12)
        return 0;
    if (nb == 1
        || nb == 0)
        return 1;
    result = nb * my_compute_factorial_rec(nb - 1);
    return result;
}
