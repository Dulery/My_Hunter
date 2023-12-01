/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_printf
*/

#include <stdarg.h>
#include "my.h"

void format_c(va_list args)
{
    my_putchar(va_arg(args, int));
}

void format_d(va_list args)
{
    my_put_nbr(va_arg(args, int));
}

void format_f(va_list args)
{
    my_put_nbr(va_arg(args, float));
}

void format_s(va_list args)
{
    my_putstr(va_arg(args, char *));
}

void format_pourcent(va_list args)
{
    my_putchar('%');
}
