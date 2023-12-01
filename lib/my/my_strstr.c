/*
** EPITECH PROJECT, 2023
** my_strstr
** File description:
** find the first occurence of a char
*/

#include <unistd.h>
#include "my.h"

static char *occurence(int i, int T, char *str, char const *to_find)
{
    if (T == 1) {
        return &str[i - my_strlen(to_find)];
    } else
        return NULL;
}

char *my_strstr(char *str, char const *to_find)
{
    int T = 0;
    int j = 0;
    int i = 0;

    if (my_strlen(to_find) == 0)
        return str;
    if (my_strlen(str) == 0 || my_strlen(to_find) > my_strlen(str))
        return 0;
    while ( to_find[j] != '\0' && (str[i] != '\0')) {
        if (str[i] == to_find[j]) {
            i++;
            j++;
            T = 1;
        } else {
            i++;
            T = 0;
            j = 0;
        }
    }
    return occurence(i, T, str, to_find);
}
