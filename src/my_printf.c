/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_printf
*/

#include <stdarg.h>
#include "../include/my.h"

void (*format_functions[])(va_list) = {
    ['%'] = format_pourcent,
    ['c'] = format_c,
    ['s'] = format_s,
    ['d'] = format_d,
    ['i'] = format_d,
    ['u'] = format_u,
    ['o'] = format_o,
    ['x'] = format_x,
    ['X'] = format_xmaj
};

void myif(char z, va_list args)
{
    if (format_functions[(int)z] != 0) {
        format_functions[(int)z](args);
    }
}

int my_printf(const char *format, ...)
{
    va_list args;
    int z = 0;

    va_start(args, format);
    while (format[z] != '\0') {
        if (format[z] == '%') {
            z++;
            myif(format[z], args);
        } else {
            my_putchar(format[z]);
        }
        z++;
    }
    va_end(args);
    return 0;
}
