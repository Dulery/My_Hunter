/*
** EPITECH PROJECT, 2023
** my_strupcase
** File description:
** return s1 in UPPER CASE
*/

#include "my.h"

char *my_strupcase(char *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
    str[my_strlen(str)] = '\0';
    return str;
}
