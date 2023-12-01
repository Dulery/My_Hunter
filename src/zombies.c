/*
** EPITECH PROJECT, 2018
** zombies
** File description:
** oui
*/

#include "../my.h"

the_game spawn_zombie(the_game the_game)
{
    the_game.i = (the_game.j.compt == 2) ? 2 : the_game.i;
    the_game.i = (the_game.j.compt == 10) ? 3 : the_game.i;
    the_game.i = (the_game.j.compt == 15) ? 4 : the_game.i;
    return (the_game);
}

int hit_zombie(int hitbox, int compt)
{
    hitbox = (compt == 5) ? 110 : hitbox;
    hitbox = (compt == 10) ? 220 : hitbox;
    hitbox = (compt == 15) ? 440 : hitbox;
    hitbox = (compt == 20) ? 330 : hitbox;
    hitbox = (compt == 25) ? 440 : hitbox;
    hitbox = (compt == 30) ? 220 : hitbox;
    return (hitbox);
}

void zombie_place(the_game the_game)
{
    for (int i = 0; i < the_game.i; i++) {
        if (the_game.z[i].vies) {
            sfSprite_setTexture(the_game.z[i].sprite,
            the_game.z[i].texture, sfTrue);
            sfSprite_setTextureRect(the_game.z[i].sprite, the_game.z[i].hit);
            sfSprite_setPosition(the_game.z[i].sprite, the_game.z[i].position);
            sfRenderWindow_drawSprite(the_game.k, the_game.z[i].sprite, NULL);
        }
    }
}

the_game my_zombie(the_game the_game)
{
    for (int i = 0; i < the_game.i; i++) {
        the_game.z[i].seconds = (the_game.z[i].time).microseconds / 10000.0;
        if (the_game.z[i].seconds > 1.0) {
            sfClock_restart(the_game.z[i].clock);
            (the_game.z[i].position).x += (the_game.z[i].mort == 3) ? 8 : 0;
            (the_game.z[i].hit).left = hit_zombie(the_game.z[i].hit.left,
            the_game.z[i].compteur);
            the_game.z[i].compteur++;
            the_game.z[i] = mort_zombie(the_game.z[i]);
            the_game.z[i].compteur = (the_game.z[i].compteur >= 30) ? 0 :
            the_game.z[i].compteur;
        }
    }
    return (the_game);
}

stc_zombie des_zombie(stc_zombie dests)
{
    stc_zombie tzombie;

    sfClock_destroy(dests.clock);
    sfSprite_destroy(dests.sprite);
    sfTexture_destroy(dests.texture);
    return (zombie(tzombie));
}
