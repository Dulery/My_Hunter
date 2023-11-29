/*
** EPITECH PROJECT, 2018
** Viseur
** File description:
** oui
*/

#include "my.h"

void viseur(the_game game)
{
    int x = 60;
    int y = 60;
    sfVector2f positionSpr;

    positionSpr.x = sfMouse_getPositionRenderWindow(game.w).x - x;
    positionSpr.y = sfMouse_getPositionRenderWindow(game.w).y - y;
    sfSprite_setPosition(game.cursorSpr, positionSpr);
    sfRenderWindow_drawSprite(game.w, game.cursorSpr, NULL);
}
