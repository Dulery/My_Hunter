/*
** EPITECH PROJECT, 2023
** my_compute_power_rec
** File description:
** power of a given int but with recursivity
*/

#include "my.h"

int my_compute_power_rec(int nb, int p)
{
    int result = nb;

    if (p == 0)
        return 1;
    if (p < 0)
        return 0;
    result = result * my_compute_power_rec(nb, p - 1);
    return result;
}
