/*
** EPITECH PROJECT, 2018
** Viseur
** File description:
** oui
*/

#include "../my.h"

void viseur(the_game game)
{
    sfVector2f positionSpr;
    int x = 60;
    int y = 60;

    positionSpr.x = sfMouse_getPositionRenderWindow(game.k).x - x;
    positionSpr.y = sfMouse_getPositionRenderWindow(game.k).y - y;
    sfSprite_setPosition(game.curseur, positionSpr);
    sfRenderWindow_drawSprite(game.k, game.curseur, NULL);
}
