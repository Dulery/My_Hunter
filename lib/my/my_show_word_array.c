/*
** EPITECH PROJECT, 2023
** my show word array
** File description:
** displays content of an array of words
*/

#include <stdlib.h>
#include "my.h"

int my_show_word_array(char *const *tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return 0;
}
