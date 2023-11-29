/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** oui
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System/Vector2.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <time.h>
#include "my.h"
#include "struct.h"

void my_destroy(game_t game)
{
    sfMusic_stop(game.h.gun1);
    for (int i = 0; i < game.i; i++) {
        sfClock_destroy(game.b[i].clock);
        sfSprite_destroy(game.b[i].sprite);
        sfTexture_destroy(game.b[i].texture);
    }
    sfSprite_destroy(game.h.sprite);
    sfTexture_destroy(game.h.text);
    sfText_destroy(game.h.txt);
    sfTexture_destroy(game.text);
    sfSprite_destroy(game.sprite);
    sfSprite_destroy(game.cursorSpr);
    sfMusic_destroy(game.h.gun1);
    sfRenderWindow_destroy(game.w);
}

int my_put_h(void)
{
    write(1, "MyHunterZ: l'objectif est de tuer des zombies\n", 47);
    write(1, "-[échape] pour quitter le jeu.\n", 32);
    write(1, "-[espace] pour mettre pause.\n", 29);
    write(1, "-[clique droit] pour utiliser le fusil.\n", 40);
    return (0);
}

int main(int ac, char *av[])
{
    game_t game;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        return (my_put_h());
    if (ac != 1)
        return (84);
    game = create_game(game);
    menu(game);
    while (sfRenderWindow_isOpen(game.w)) {
        my_draw_window(game);
        game = my_gun(game);
        game = my_bird(game);
        put_text(game);
        my_cursor(game);
        game = my_replay(game);
    }
    my_destroy(game);
    return (0);
}
