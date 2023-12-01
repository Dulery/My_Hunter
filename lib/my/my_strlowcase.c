/*
** EPITECH PROJECT, 2023
** my_strlowcase
** File description:
** return s1 in lower case
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
    return str;
}
