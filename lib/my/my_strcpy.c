/*
** EPITECH PROJECT, 2023
** my_strcpy
** File description:
** copy a string to another
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    for (int i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[my_strlen(src)] = '\0';
    return dest;
}
