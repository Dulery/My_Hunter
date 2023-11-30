/*
** EPITECH PROJECT, 2018
** zombies
** File description:
** oui
*/

#include "my.h"

the_game spawn_zombie(the_game game)
{
    game.i = (game.j.compt == 4) ? 2 : game.i;
    game.i = (game.j.compt == 10) ? 3 : game.i;
    game.i = (game.j.compt == 15) ? 4 : game.i;
    game.i = (game.j.compt == 30) ? 5 : game.i;
    return (game);
}

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

void zombie_place(the_game game)
{
    for (int i = 0; i < game.i; i++) {
        if (game.z[i].vies) {
            sfSprite_setTexture(game.z[i].sprite, game.z[i].texture, sfTrue);
            sfSprite_setTextureRect(game.z[i].sprite, game.z[i].rect);
            sfSprite_setPosition(game.z[i].sprite, game.z[i].position);
            sfRenderWindow_drawSprite(game.k, game.z[i].sprite, NULL);
        }
    }
}

the_game my_zombie(the_game game)
{
    for (int i = 0; i < game.i; i++) {
        game.z[i].time = sfClock_getElapsedTime(game.z[i].clock);
        game.z[i].seconds = (game.z[i].time).microseconds / 10000.0;
        if (game.z[i].seconds > 1.0) {
            sfClock_restart(game.z[i].clock);
            (game.z[i].position).x += (game.z[i].mort == 3) ? 6 : 0;
            (game.z[i].rect).left = hit_zombie(game.z[i].rect.left,
            game.z[i].compteur);
            game.z[i].compteur = (game.z[i].compteur >= 30) ? 0 :
            game.z[i].compteur;
            game.z[i].compteur++;
            game.z[i] = mort_zombie(game.z[i]);
        }
    }
    return (game);
}

stc_zombie des_zombie(stc_zombie old)
{
    stc_zombie tzombie;

    sfClock_destroy(old.clock);
    sfSprite_destroy(old.sprite);
    sfTexture_destroy(old.texture);
    return (zombie(tzombie));
}
