/*
** EPITECH PROJECT, 2023
** my putchar
** File description:
** put charachter
*/

#include <unistd.h>
#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
