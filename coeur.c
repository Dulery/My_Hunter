/*
** EPITECH PROJECT, 2023
** vie.c
** File description:
** oui
*/

#include "my.h"

the_game player_heart(the_game game)
{
    for (int i = 0; i < game.i; i++) {
        if (game.z[i].position.x > 1400) {
            game.j.heart--;
            game.z[i] = des_zombie(game.z[i]);
            game.j.rect.width -= 15;
        }
    }
    if (game.j.heart <= 0) {
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

char *my_get_score(int nb)
{
    char *str = malloc(sizeof(char) * 13);
    int temps;
    int i = -1;

    for (int compt = nb; compt >= 1; i++)
        compt = compt / 10;
    temps = i;
    for (; nb >= 1; i--) {
        str[i] = nb % 10 + 48;
        nb = nb / 10;
    }
    str[temps + 1] = '\0';
    if (str[0] == '\0') {
        str[0] = '0';
        str[1] = '\0';
    }
    return (str);
}

void put_text(the_game game)
{
    char *str = my_get_score(game.j.compt);

    game.j.position.y += 20;
    sfText_setString(game.j.txt, str);
    sfText_setPosition(game.j.txt, game.j.position);
    sfRenderWindow_drawText(game.k, game.j.txt, NULL);
}
