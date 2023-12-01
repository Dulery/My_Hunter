/*
** EPITECH PROJECT, 2023
** vie.c
** File description:
** oui
*/

#include "../my.h"

char *score(int nombre)
{
    int temps;
    int i = -1;
    char *str = malloc(sizeof(char) * 13);

    for (int countagain = nombre; countagain >= 1; i++)
        countagain = countagain / 10;
    temps = i;
    for (; nombre >= 1; i--) {
        str[i] = nombre % 10 + 48;
        nombre = nombre / 10;
    }
    str[temps + 1] = '\0';
    return str;
}

the_game player_heart(the_game the_game)
{
    for (int i = 0; i < the_game.i; i++) {
        if (the_game.z[i].position.x > 1400) {
            the_game.j.coeurs--;
            the_game.z[i] = des_zombie(the_game.z[i]);
            the_game.j.rect.width -= 20;
        }
    }
    if (the_game.j.coeurs <= 0) {
        the_game.jeu = 0;
    }
    put_heart(the_game);
    return (the_game);
}

void put_heart(the_game the_game)
{
    sfSprite_setTexture(the_game.j.sprite, the_game.j.text, sfTrue);
    sfSprite_setTextureRect(the_game.j.sprite, the_game.j.rect);
    sfSprite_setPosition(the_game.j.sprite, the_game.j.position);
    sfRenderWindow_drawSprite(the_game.k, the_game.j.sprite, NULL);
}

void put_text(the_game the_game)
{
    char *str = score(the_game.j.compt);

    the_game.j.position.y += 20;
    sfText_setString(the_game.j.textbase, str);
    sfText_setPosition(the_game.j.textbase, the_game.j.position);
    sfRenderWindow_drawText(the_game.k, the_game.j.textbase, NULL);
}
