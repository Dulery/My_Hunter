/*
** EPITECH PROJECT, 2018
** window
** File description:
** oui
*/

#include "my.h"

void make_window(the_game game)
{
    sfRenderWindow_display(game.k);
    sfRenderWindow_drawSprite(game.k, game.sprite, NULL);
    while (sfRenderWindow_pollEvent(game.k, &game.event)) {
        if (game.event.type == sfEvtClosed)
            sfRenderWindow_close(game.k);
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(game.k);
}
