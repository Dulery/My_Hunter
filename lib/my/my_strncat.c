/*
** EPITECH PROJECT, 2023
** my strncat
** File description:
** str n cat
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int size_dest = my_strlen(dest);

    for (int i = 0; i < nb; i++)
        dest[size_dest + i] = src[i];
    return dest;
}
