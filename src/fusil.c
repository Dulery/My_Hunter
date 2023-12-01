/*
** EPITECH PROJECT, 2023
** fusil.c
** File description:
** oui
*/

#include "../my.h"

stc_zombie mort_zombie(stc_zombie tzombie)
{
    int c = tzombie.mort;

    if (c < 3) {
        tzombie.hit.width = 80;
        tzombie.hit.top = 110;
        tzombie.hit.left = (c < 3 && c >= -5) ? 100 : tzombie.hit.left;
        tzombie.hit.left = (c < -5 && c >= -13) ? 180 : tzombie.hit.left;
        tzombie.hit.left = (c < -13 && c >= -21) ? 360 : tzombie.hit.left;
        tzombie.hit.left = (c < -21) ? 460 : tzombie.hit.left;
        tzombie = (c == -29) ? des_zombie(tzombie) : tzombie;
        tzombie.mort = (tzombie.mort == 3) ? tzombie.mort : c - 1;
    }
    return (tzombie);
}

int my_shoot(stc_zombie tzombie, sfRenderWindow *window)
{
    int y = sfMouse_getPositionRenderWindow(window).y;
    int x = sfMouse_getPositionRenderWindow(window).x;

    if ((tzombie.position).x + 100 > x && (tzombie.position).x < x &&
    tzombie.position.y + 100 > y &&
    tzombie.position.y < y && tzombie.mort == 3) {
        return (1);
    } else {
        return (0);
    }
}

void my_gun_song(the_game the_game)
{
    sfMusic_play(the_game.j.fusilsound);
}

the_game fusil_fon(the_game the_game)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        my_gun_song(the_game);
        for (int i = 0; i < the_game.i; i++) {
            the_game.j.compt += my_shoot(the_game.z[i], the_game.k);
            the_game.z[i].mort = (my_shoot(the_game.z[i],
            the_game.k)) ? 2 : the_game.z[i].mort;
        }
    }
    the_game = player_heart(the_game);
    zombie_place(the_game);
    return (spawn_zombie(the_game));
}
