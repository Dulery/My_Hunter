/*
** EPITECH PROJECT, 2023
** my_flags
** File description:
** my_flags
*/

#include <stdarg.h>
#include "my.h"

void format_x(va_list args)
{
    my_putnbr_hexa(va_arg(args, unsigned int), "0123456789abcdef");
}

void format_xmaj(va_list args)
{
    my_putnbr_hexa(va_arg(args, unsigned int), "0123456789ABCDEF");
}

void format_o(va_list args)
{
    my_putnbr_hexa(va_arg(args, unsigned int), "01234567");
}

void format_e(va_list args)
{
    my_putnbr_hexa(va_arg(args, double));
}

void format_u(va_list args)
{
    my_putnbr_hexa(va_arg(args, unsigned int), "0123456789");
}
