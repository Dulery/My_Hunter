/*
** EPITECH PROJECT, 2018
** zombies
** File description:
** oui
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "struct.h"
#include "my.h"
#include <stdio.h>

int hit_zombie(int rect, int compt)
{
    rect = (compt == 5) ? 110 : rect;
    rect = (compt == 10) ? 220 : rect;
    rect = (compt == 15) ? 440 : rect;
    rect = (compt == 20) ? 330 : rect;
    rect = (compt == 25) ? 440 : rect;
    rect = (compt == 30) ? 220 : rect;
    return (rect);
}

the_game my_zombie(the_game game)
{
    for (int i = 0; i < game.i; i++) {
        game.b[i].time = sfClock_getElapsedTime(game.b[i].clock);
        game.b[i].seconds = (game.b[i].time).microseconds / 10000.0;
        if (game.b[i].seconds > 1.0) {
            sfClock_restart(game.b[i].clock);
            (game.b[i].position).x += (game.b[i].death == 3) ? 6 : 0;
            (game.b[i].rect).left = hit_zombie(game.b[i].rect.left,
            game.b[i].compt);
            game.b[i].compt = (game.b[i].compt >= 30) ? 0 : game.b[i].compt;
            game.b[i].compt++;
            game.b[i] = mort_zombie(game.b[i]);
        }
    }
    return (game);
}

void zombie_place(the_game game)
{
    for (int i = 0; i < game.i; i++) {
        if (game.b[i].heart) {
            sfSprite_setTexture(game.b[i].sprite, game.b[i].texture, sfTrue);
            sfSprite_setTextureRect(game.b[i].sprite, game.b[i].rect);
            sfSprite_setPosition(game.b[i].sprite, game.b[i].position);
            sfRenderWindow_drawSprite(game.w, game.b[i].sprite, NULL);
        }
    }
}

stc_zombie des_zombie(stc_zombie old)
{
    stc_zombie bird;

    sfClock_destroy(old.clock);
    sfSprite_destroy(old.sprite);
    sfTexture_destroy(old.texture);
    return (zombie(bird));
}

the_game spawn_zombie(the_game game)
{
    game.i = (game.h.compt == 4) ? 2 : game.i;
    game.i = (game.h.compt == 10) ? 3 : game.i;
    game.i = (game.h.compt == 15) ? 4 : game.i;
    game.i = (game.h.compt == 30) ? 5 : game.i;
    return (game);
}
