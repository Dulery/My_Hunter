/*
** EPITECH PROJECT, 2023
** fusil.c
** File description:
** oui
*/

#include <time.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my.h"
#include "struct.h"
#include <stdio.h>

stc_zombie mort_zombie(stc_zombie bird)
{
    int c = bird.death;

    if (c < 3) {
        bird.rect.width = 80;
        bird.rect.top = 110;
        bird.rect.left = (c < 3 && c >= -5) ? 100 : bird.rect.left;
        bird.rect.left = (c < -5 && c >= -13) ? 180 : bird.rect.left;
        bird.rect.left = (c < -13 && c >= -21) ? 360 : bird.rect.left;
        bird.rect.left = (c < -21) ? 460 : bird.rect.left;
        bird = (c == -29) ? des_zombie(bird) : bird;
        bird.death = (bird.death == 3) ? bird.death : c - 1;
    }
    return (bird);
}

void my_gun_song(the_game game)
{
    sfMusic_play(game.h.gun1);
}

int my_shoot(stc_zombie bird, sfRenderWindow *window)
{
    int x = sfMouse_getPositionRenderWindow(window).x;
    int y = sfMouse_getPositionRenderWindow(window).y;

    if ((bird.position).x + 100 > x && (bird.position).x < x &&
    bird.position.y + 100 > y && bird.position.y < y && bird.death == 3)
        return (1);
    else
        return (0);
}

the_game my_gun(the_game game)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        my_gun_song(game);
        for (int i = 0; i < game.i; i++) {
            game.h.compt += my_shoot(game.b[i], game.w);
            game.b[i].death = (my_shoot(game.b[i],
            game.w)) ? 2 : game.b[i].death;
        }
    }
    game = player_heart(game);
    zombie_place(game);
    return (spawn_zombie(game));
}
