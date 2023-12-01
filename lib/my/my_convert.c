/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_printf
*/

#include <stdarg.h>
#include "include/my.h"

int calcule_expo(double *number)
{
    int expo = 0;
    while (*number >= 10.0) {
        *number /= 10.0;
        expo++;
    }
    while (*number < 1.0) {
        *number *= 10.0;
        expo--;
    }
    return expo;
}

void affiche_expo(int expo)
{
    my_putchar('e');
    if (expo >= 0) {
        my_putchar('+');
    } else {
        my_putchar('-');
        expo = -expo;
    }
    if (expo < 10) {
        my_putchar('0');
    }
    my_put_nbr(expo / 10);
    my_put_nbr(expo % 10);
    my_putstr("\n");
}

void my_convertsci(double number, int precision)
{
    int expo = calcule_expo(&number);
    char n[20];
    int integer_part = (int)number;
    double fractional_part = number - integer_part;
    double digits = 0;

    if (number == 0) {
        my_putstr("0.0e+00\n");
        return;
    }
    
    my_put_nbr(integer_part);
    my_putchar('.');

    while (digits < precision) {
        fractional_part *= 10;
        int digit = (int)fractional_part;
        my_put_nbr(digit);
        fractional_part -= digit;
        digits++;
    }

    affiche_expo(expo);
}

int main() {
    double n = 1231554.89;
    my_convertsci(n, 6);
    return 0;
}
