/*
** EPITECH PROJECT, 2023
** my_putnbr_base
** File description:
** my_putnbr_hexa
*/

void my_putnbr_hexa(int nbr, char *base)
{
    int base_length = 0;

    while (base[base_length] != '\0') {
        base_length++;
    }
    if (base_length < 2) {
        my_putstr("La base doit avoir au moins 2 caractères.\n");
        return;
    }
    if (nbr < 0) {
        my_putchar('-');
        nbr = -nbr;
    }
    if (nbr < base_length) {
        my_putchar(base[nbr]);
    } else {
        my_putnbr_hexa(nbr / base_length, base);
        my_putnbr_hexa(nbr % base_length, base);
    }
}
