/*
** EPITECH PROJECT, 2023
** my_strncpy*
** File description:
** copy n characters from str to dest str
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n) {
        if (src[i] == '\0') {
            dest[i] = '\0';
            return dest;
        } else
            dest[i] = src[i];
        i++;
    }
    return dest;
}
