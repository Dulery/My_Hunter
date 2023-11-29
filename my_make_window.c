/*
** EPITECH PROJECT, 2018
** window
** File description:
** oui
*/

#include "my.h"

void make_window(the_game game)
{
    sfRenderWindow_display(game.w);
    sfRenderWindow_drawSprite(game.w, game.sprite, NULL);
    while (sfRenderWindow_pollEvent(game.w, &game.event)) {
        if (game.event.type == sfEvtClosed)
            sfRenderWindow_close(game.w);
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(game.w);
}
