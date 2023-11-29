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
        if (game.b[i].position.x > 1400) {
            game.h.heart--;
            game.b[i] = des_zombie(game.b[i]);
            game.h.rect.width -= 15;
        }
    }
    if (game.h.heart <= 0) {
        game.game = 0;
    }
    put_heart(game);
    return (game);
}

void put_heart(the_game game)
{
    sfSprite_setTexture(game.h.sprite, game.h.text, sfTrue);
    sfSprite_setTextureRect(game.h.sprite, game.h.rect);
    sfSprite_setPosition(game.h.sprite, game.h.position);
    sfRenderWindow_drawSprite(game.w, game.h.sprite, NULL);
}

char *my_get_score(int nb)
{
    char *str = malloc(sizeof(char) * 13);
    int tmp;
    int i = -1;

    for (int compt = nb; compt >= 1; i++)
        compt = compt / 10;
    tmp = i;
    for (; nb >= 1; i--) {
        str[i] = nb % 10 + 48;
        nb = nb / 10;
    }
    str[tmp + 1] = '\0';
    if (str[0] == '\0') {
        str[0] = '0';
        str[1] = '\0';
    }
    return (str);
}

void put_text(the_game game)
{
    char *str = my_get_score(game.h.compt);

    game.h.position.y += 20;
    sfText_setString(game.h.txt, str);
    sfText_setPosition(game.h.txt, game.h.position);
    sfRenderWindow_drawText(game.w, game.h.txt, NULL);
}
