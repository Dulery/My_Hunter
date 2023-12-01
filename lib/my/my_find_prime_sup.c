/*
** EPITECH PROJECT, 2023
** my_find_prime_sup
** File description:
** smallest prime number after given int
*/

#include "my.h"

static int my_is_prime2(int nb)
{
    int count_divider = 0;

    for (int i = 2; i < nb; i++) {
        if (nb % i == 0) {
            count_divider++;
        }
    }
    if (count_divider > 0)
        return 0;
    return 1;
}

int my_find_prime_sup(int nb)
{
    if (nb == 1 || nb <= 0)
        return 2;
    else if (my_is_prime2(nb) == 1)
        return nb;
    for (int i = nb; i < nb * 2; i++) {
        if (my_is_prime2(i) == 1)
            return i;
        }
    return 0;
}
