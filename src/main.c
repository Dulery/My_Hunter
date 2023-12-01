/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** oui
*/

#include "../my.h"
#include <stdio.h>

int print_h(void)
{
    printf("bonjour");
    return (0);
}

int main(int ac, char *av[])
{
    the_game the_game;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        return (print_h());
    }
    if (ac != 1) {
        return (84);
    }
    the_game = make_game(the_game);
    bestmusicofalltime(the_game);
    menu(the_game);
    while (sfRenderWindow_isOpen(the_game.k)) {
        make_window(the_game);
        the_game = fusil_fon(the_game);
        the_game = my_zombie(the_game);
        put_text(the_game);
        viseur(the_game);
        the_game = restart(the_game);
    }
    my_destroy(the_game);
    return 0;
}

int bestmusicofalltime(the_game the_game)
{
    the_game.j.music = sfMusic_createFromFile("content/sound/playsong.ogg");
    sfMusic_setLoop(the_game.j.music, sfTrue);
    sfMusic_play(the_game.j.music);
    return 0;
}

void my_destroy(the_game the_game)
{
    sfMusic_stop(the_game.j.fusilsound);
    for (int i = 0; i < the_game.i; i++) {
        sfClock_destroy(the_game.z[i].clock);
        sfSprite_destroy(the_game.z[i].sprite);
        sfTexture_destroy(the_game.z[i].texture);
    }
    sfText_destroy(the_game.j.textbase);
    sfSprite_destroy(the_game.j.sprite);
    sfTexture_destroy(the_game.j.text);
    sfTexture_destroy(the_game.scoretext);
    sfSprite_destroy(the_game.sprite);
    sfSprite_destroy(the_game.curseur);
    sfMusic_destroy(the_game.j.fusilsound);
    sfRenderWindow_destroy(the_game.k);
}

void viseur(the_game the_game)
{
    sfVector2f positionSpr;
    int x = 60;
    int y = 60;

    positionSpr.x = sfMouse_getPositionRenderWindow(the_game.k).x - x;
    positionSpr.y = sfMouse_getPositionRenderWindow(the_game.k).y - y;
    sfSprite_setPosition(the_game.curseur, positionSpr);
    sfRenderWindow_drawSprite(the_game.k, the_game.curseur, NULL);
}
