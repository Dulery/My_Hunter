/*
** EPITECH PROJECT, 2023
** vie.c
** File description:
** oui
*/

#include "../my.h"

char *my_get_score(int nombre)
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
    if (str[0] == '\0') {
        str[0] = '0';
        str[1] = '\0';
    }
    return (str);
}

the_game player_heart(the_game game)
{
    for (int i = 0; i < game.i; i++) {
        if (game.z[i].position.x > 1400) {
            game.j.coeurs--;
            game.z[i] = des_zombie(game.z[i]);
            game.j.rect.width -= 20;
        }
    }
    if (game.j.coeurs <= 0) {
        game.game = 0;
    }
    put_heart(game);
    return (game);
}

void put_heart(the_game game)
{
    sfSprite_setTexture(game.j.sprite, game.j.text, sfTrue);
    sfSprite_setTextureRect(game.j.sprite, game.j.rect);
    sfSprite_setPosition(game.j.sprite, game.j.position);
    sfRenderWindow_drawSprite(game.k, game.j.sprite, NULL);
}

void put_text(the_game game)
{
    char *str = my_get_score(game.j.compt);

    game.j.position.y += 20;
    sfText_setString(game.j.textbase, str);
    sfText_setPosition(game.j.textbase, game.j.position);
    sfRenderWindow_drawText(game.k, game.j.textbase, NULL);
}
