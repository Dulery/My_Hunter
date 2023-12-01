/*
** EPITECH PROJECT, 2023
** my_revstr
** File description:
** reverse a string
*/

#include "my.h"

char *my_revstr(char *str)
{
    int i = 0;
    int len = 0;
    char temp;

    while (str[len] != '\0') {
        len++;
    }
    while (i < len) {
        temp = str[i];
        str[i] = str[len - 1];
        str[len - 1] = temp;
        i++;
        len--;
    }
    return str;
}
