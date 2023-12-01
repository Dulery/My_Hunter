/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** oui
*/

#include "../my.h"

int put_h(void)
{
    write(1, "MyHunterZ: l'objectif est de tuer des zombies\n", 47);
    write(1, "-[échape] pour quitter le jeu.\n", 32);
    write(1, "-[espace] pour mettre pause.\n", 29);
    write(1, "-[clique droit] pour utiliser le fusil.\n", 40);
    return (0);
}

int main(int ac, char *av[])
{
    the_game game;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        return (put_h());
    if (ac != 1)
        return (84);
    game = make_game(game);
    bestmusicofalltime(game);
    menu(game);
    while (sfRenderWindow_isOpen(game.k)) {
        make_window(game);
        game = my_gun(game);
        game = my_zombie(game);
        put_text(game);
        viseur(game);
        game = my_replay(game);
    }
    my_destroy(game);
    return 0;
}

int bestmusicofalltime(the_game game)
{
    game.j.music = sfMusic_createFromFile("resource/song/playsong.ogg");
    sfMusic_setLoop(game.j.music, sfTrue);
    sfMusic_play(game.j.music);
    return 0;
}

void my_destroy(the_game game)
{
    sfMusic_stop(game.j.fusilsound);
    for (int i = 0; i < game.i; i++) {
        sfClock_destroy(game.z[i].clock);
        sfSprite_destroy(game.z[i].sprite);
        sfTexture_destroy(game.z[i].texture);
    }
    sfText_destroy(game.j.txt);
    sfSprite_destroy(game.j.sprite);
    sfTexture_destroy(game.j.text);
    sfTexture_destroy(game.text);
    sfSprite_destroy(game.sprite);
    sfSprite_destroy(game.cursorSpr);
    sfMusic_destroy(game.j.fusilsound);
    sfRenderWindow_destroy(game.k);
}
