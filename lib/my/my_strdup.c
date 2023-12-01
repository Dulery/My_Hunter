/*
** EPITECH PROJECT, 2023
** strdup
** File description:
** allocates memory and copies the string given as argument in it
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(src)) + 1);

    str = my_strcpy(str, src);
    return str;
}
