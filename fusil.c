/*
** EPITECH PROJECT, 2023
** fusil.c
** File description:
** oui
*/

#include "my.h"

stc_zombie mort_zombie(stc_zombie tzombie)
{
    int c = tzombie.mort;

    if (c < 3) {
        tzombie.rect.width = 80;
        tzombie.rect.top = 110;
        tzombie.rect.left = (c < 3 && c >= -5) ? 100 : tzombie.rect.left;
        tzombie.rect.left = (c < -5 && c >= -13) ? 180 : tzombie.rect.left;
        tzombie.rect.left = (c < -13 && c >= -21) ? 360 : tzombie.rect.left;
        tzombie.rect.left = (c < -21) ? 460 : tzombie.rect.left;
        tzombie = (c == -29) ? des_zombie(tzombie) : tzombie;
        tzombie.mort = (tzombie.mort == 3) ? tzombie.mort : c - 1;
    }
    return (tzombie);
}

void my_gun_song(the_game game)
{
    sfMusic_play(game.j.gun1);
}

int my_shoot(stc_zombie tzombie, sfRenderWindow *window)
{
    int x = sfMouse_getPositionRenderWindow(window).x;
    int y = sfMouse_getPositionRenderWindow(window).y;

    if ((tzombie.position).x + 100 > x && (tzombie.position).x < x &&
    tzombie.position.y + 100 > y &&
    tzombie.position.y < y && tzombie.mort == 3)
        return (1);
    else
        return (0);
}

the_game my_gun(the_game game)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        my_gun_song(game);
        for (int i = 0; i < game.i; i++) {
            game.j.compt += my_shoot(game.z[i], game.k);
            game.z[i].mort = (my_shoot(game.z[i],
            game.k)) ? 2 : game.z[i].mort;
        }
    }
    game = player_heart(game);
    zombie_place(game);
    return (spawn_zombie(game));
}
