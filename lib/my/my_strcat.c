/*
** EPITECH PROJECT, 2023
** my str cat
** File description:
** concatenate two str
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int count = 0;
    int size_dest = my_strlen(dest);
    int size_src = my_strlen(src);

    for (int i = size_dest; i < size_dest + size_src; i++) {
        dest[i] = src[count];
        count++;
    }
    dest[size_dest + size_src] = '\0';
    return dest;
}
