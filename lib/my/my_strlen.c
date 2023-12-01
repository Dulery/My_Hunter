/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** counting number of characters in the string
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        count++;
        i++;
    }
    return count;
}
