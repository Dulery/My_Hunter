/*
** EPITECH PROJECT, 2023
** print_p.c
** File description:
** oui
*/

#include "include/my.h"

void myfor(char *reversedstock, char *stock, int index)
{
    for (int i = 0; i < index; i++) {
        reversedstock[i] = stock[index - 1 - i];
    }
    reversedstock[index] = '\0';
    for (int i = 0; i < index; i++) {
        my_putchar(reversedstock[i]);
    }
    my_putchar('\n');
}

void print_p(void *ptr)
{
    char stock[16];
    const char hexChars[] = "0123456789ABCDEF";
    unsigned long long int address = (unsigned long long int)ptr;
    int index = 0;
    char reversedstock[16];

    while (address > 0) {
        stock[index] = hexChars[address % 16];
        address /= 16;
        index++;
    }
    stock[index++] = 'x';
    stock[index++] = '0';
    myfor(reversedstock, stock, index);
}

int main(void)
{
    int x = 42;
    print_p(&x);
    return 0;
}
