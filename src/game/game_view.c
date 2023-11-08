/*
** EPITECH PROJECT, 2023
** game_view.c
** File description:
** oui
*/

#include <unistd.h>
#include "../../include/my.h"

void game_function(sfRenderWindow* window, sfEvent event)
{
    sfTexture *gamefield = sfTexture_createFromFile("content/gamefield.jpeg", NULL);
    sfSprite *gamefield_sprite = sfSprite_create();

    sfSprite_setTexture(gamefield_sprite, gamefield, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
        }
        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_drawSprite(window, gamefield_sprite, NULL);
        sfRenderWindow_display(window);
    }
}
