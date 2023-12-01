/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** en gros ça devient une string
*/

#include <stddef.h>
#include "my.h"

int my_putstr(char *str)
{
    if (str == NULL) {
        return 0;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return 0;
}
