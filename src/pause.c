/*
** EPITECH PROJECT, 2018
** menupause
** File description:
** oui
*/

#include "../my.h"

void my_draw_pause(the_game game)
{
    sfVector2f position = {750, 350};
    sfVector2f position2 = {550, 350};
    sfTexture *texture[3];
    sfSprite *sprite[3];

    sprite[1] = sfSprite_create();
    texture[1] = sfTexture_createFromFile("resource/picture/res.png", NULL);
    sfSprite_setTexture(sprite[1], texture[1], sfTrue);
    sfSprite_setPosition(sprite[1], position);
    sfRenderWindow_drawSprite(game.k, sprite[1], NULL);
    sprite[2] = sfSprite_create();
    texture[2] = sfTexture_createFromFile("resource/picture/pause.png", NULL);
    sfSprite_setTexture(sprite[2], texture[2], sfTrue);
    sfSprite_setPosition(sprite[2], position2);
    sfRenderWindow_drawSprite(game.k, sprite[2], NULL);
}

the_game my_menu_event(the_game game)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    sfMouse_getPositionRenderWindow(game.k).x > 750 &&
    sfMouse_getPositionRenderWindow(game.k).x < 750 + 100 &&
    sfMouse_getPositionRenderWindow(game.k).y > 350 &&
    sfMouse_getPositionRenderWindow(game.k).y < 350 + 100)
        game = remake_game(game);
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    sfMouse_getPositionRenderWindow(game.k).x > 550 &&
    sfMouse_getPositionRenderWindow(game.k).x < 550 + 100 &&
    sfMouse_getPositionRenderWindow(game.k).y > 350 &&
    sfMouse_getPositionRenderWindow(game.k).y < 350 + 100)
        game.boucle = 0;
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    sfMouse_getPositionRenderWindow(game.k).x > 550 + 100 &&
    sfMouse_getPositionRenderWindow(game.k).x < 550 + 200 &&
    sfMouse_getPositionRenderWindow(game.k).y > 350 &&
    sfMouse_getPositionRenderWindow(game.k).y < 350 + 100)
        sfRenderWindow_close(game.k);
    return (game);
}

void window_close(the_game game)
{
    while (sfRenderWindow_pollEvent(game.k, &game.event)) {
        if (game.event.type == sfEvtClosed) {
            sfRenderWindow_close(game.k);
        }
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        sfRenderWindow_close(game.k);
    }
}

the_game pause_part2(the_game game)
{
    while (game.boucle && sfRenderWindow_isOpen(game.k)) {
        window_close(game);
        game = my_menu_event(game);
        while (sfKeyboard_isKeyPressed(sfKeySpace)) {
            window_close(game);
            game.boucle = 0;
        }
    }
    return (game);
}

the_game my_pause(the_game game)
{
    game.boucle = 0;
    while (sfKeyboard_isKeyPressed(sfKeySpace) &&
    sfRenderWindow_isOpen(game.k)) {
        if (!game.boucle) {
            my_draw_pause(game);
            sfRenderWindow_display(game.k);
        }
        game.boucle = 1;
        sfRenderWindow_setMouseCursorVisible(game.k, 1);
        window_close(game);
    }
    game = pause_part2(game);
    sfRenderWindow_setMouseCursorVisible(game.k, 0);
    return (game);
}
