/*
** EPITECH PROJECT, 2023
** my_is_prime
** File description:
** prime numberrr
*/

int my_is_prime(int nb)
{
    int count_divider = 0;

    if (nb <= 0
        || nb == 1)
        return 0;
    for (int i = 2; i < nb; i++) {
        if (nb % i == 0) {
            count_divider++;
        }
    }
    if (count_divider > 0)
        return 0;
    return 1;
}
