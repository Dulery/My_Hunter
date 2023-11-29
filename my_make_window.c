/*
** EPITECH PROJECT, 2018
** window
** File description:
** oui
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System/Vector2.h>
#include <time.h>
#include "struct.h"

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
