/*
** EPITECH PROJECT, 2023
** my_strncpm
** File description:
** return int but comparing only to n elements
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int size_s1 = my_strlen(s1);
    int size_s2 = my_strlen(s2);
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && i < n) {
        my_putchar('|');
        if (s1[i] < s2[i])
            return -1;
        if (s1[i] > s2[i])
            return 1;
        i++;
    }
    return s1[i]-s2[i];
}
