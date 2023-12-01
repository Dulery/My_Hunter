/*
** EPITECH PROJECT, 2018
** menupause
** File description:
** oui
*/

#include "../my.h"

void my_draw_pause(the_game the_game)
{
    sfVector2f position = {750, 350};
    sfVector2f position2 = {550, 350};
    sfTexture *texture[3];
    sfSprite *sprite[3];

    sprite[1] = sfSprite_create();
    texture[1] = sfTexture_createFromFile("content/image/res.png", NULL);
    sfSprite_setTexture(sprite[1], texture[1], sfTrue);
    sfSprite_setPosition(sprite[1], position);
    sfRenderWindow_drawSprite(the_game.k, sprite[1], NULL);
    sprite[2] = sfSprite_create();
    texture[2] = sfTexture_createFromFile("content/image/pause.png", NULL);
    sfSprite_setTexture(sprite[2], texture[2], sfTrue);
    sfSprite_setPosition(sprite[2], position2);
    sfRenderWindow_drawSprite(the_game.k, sprite[2], NULL);
}

the_game my_menu_event(the_game the_game)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    sfMouse_getPositionRenderWindow(the_game.k).x > 750 &&
    sfMouse_getPositionRenderWindow(the_game.k).x < 750 + 100 &&
    sfMouse_getPositionRenderWindow(the_game.k).y > 350 &&
    sfMouse_getPositionRenderWindow(the_game.k).y < 350 + 100)
        the_game = reload_game(the_game);
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    sfMouse_getPositionRenderWindow(the_game.k).x > 550 &&
    sfMouse_getPositionRenderWindow(the_game.k).x < 550 + 100 &&
    sfMouse_getPositionRenderWindow(the_game.k).y > 350 &&
    sfMouse_getPositionRenderWindow(the_game.k).y < 350 + 100)
        the_game.boucle = 0;
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    sfMouse_getPositionRenderWindow(the_game.k).x > 550 + 100 &&
    sfMouse_getPositionRenderWindow(the_game.k).x < 550 + 200 &&
    sfMouse_getPositionRenderWindow(the_game.k).y > 350 &&
    sfMouse_getPositionRenderWindow(the_game.k).y < 350 + 100)
        sfRenderWindow_close(the_game.k);
    return (the_game);
}

void window_close(the_game the_game)
{
    while (sfRenderWindow_pollEvent(the_game.k, &the_game.event)) {
        if (the_game.event.type == sfEvtClosed) {
            sfRenderWindow_close(the_game.k);
        }
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        sfRenderWindow_close(the_game.k);
    }
}

the_game pause_part2(the_game the_game)
{
    while (the_game.boucle && sfRenderWindow_isOpen(the_game.k)) {
        window_close(the_game);
        the_game = my_menu_event(the_game);
        while (sfKeyboard_isKeyPressed(sfKeySpace)) {
            window_close(the_game);
            the_game.boucle = 0;
        }
    }
    return (the_game);
}

the_game my_pause(the_game the_game)
{
    the_game.boucle = 0;
    while (sfKeyboard_isKeyPressed(sfKeySpace) &&
    sfRenderWindow_isOpen(the_game.k)) {
        if (!the_game.boucle) {
            my_draw_pause(the_game);
            sfRenderWindow_display(the_game.k);
        }
        the_game.boucle = 1;
        sfRenderWindow_setMouseCursorVisible(the_game.k, 1);
        window_close(the_game);
    }
    the_game = pause_part2(the_game);
    return (the_game);
}
