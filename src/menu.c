/*
** EPITECH PROJECT, 2018
** allmenu.c
** File description:
** oui
*/

#include "../my.h"

stc_menu create_menu(stc_menu menu)
{
    sfVector2f menuspr_logo_scale = {10, 10};
    menu.position.x = 370;
    menu.position.y = 400;
    menu.pos_text = (sfVector2f){1200, 0};
    menu.pos_logo.x = 425;
    menu.pos_logo.y = -20;
    menu.spr_logo = sfSprite_create();
    menu.spr_b1 = sfSprite_create();
    menu.text = sfTexture_createFromFile("resource/picture/play.png", NULL);
    menu.text2 = sfTexture_createFromFile("resource/picture/replay.png", NULL);
    menu.text3 = sfTexture_createFromFile("resource/picture/logo.png", NULL);
    menu.txt = sfText_create();
    sfText_setFont(menu.txt, sfFont_createFromFile("resource/picture/pl.ttf"));
    sfText_setCharacterSize(menu.txt, 100);
    sfSprite_setScale(menu.spr_logo, menuspr_logo_scale);
    sfSprite_setTexture(menu.spr_b1, menu.text, sfTrue);
    sfSprite_setTexture(menu.spr_logo, menu.text3, sfTrue);
    sfSprite_setPosition(menu.spr_logo, menu.pos_logo);
    return (menu);
}

void menu(the_game game)
{
    int loop = 1;

    while (loop && sfRenderWindow_isOpen(game.k)) {
        make_window(game);
        sfSprite_setTexture(game.m.spr_b1, game.m.text, sfTrue);
        sfSprite_setPosition(game.m.spr_b1, game.m.position);
        sfRenderWindow_drawSprite(game.k, game.m.spr_b1, NULL);
        sfRenderWindow_drawSprite(game.k, game.m.spr_logo, NULL);
        sfText_setString(game.m.txt, game.m.score);
        sfText_setPosition(game.m.txt, game.m.pos_text);
        sfRenderWindow_drawText(game.k, game.m.txt, NULL);
        loop = (sfKeyboard_isKeyPressed(sfKeyEscape)) ? 0 : loop;
        while (sfMouse_isButtonPressed(sfMouseLeft) &&
        sfMouse_getPositionRenderWindow(game.k).x > 370 &&
        sfMouse_getPositionRenderWindow(game.k).x < 988 &&
        sfMouse_getPositionRenderWindow(game.k).y > 400 &&
        sfMouse_getPositionRenderWindow(game.k).y < 555)
            loop = 0;
    }
    sfRenderWindow_setMouseCursorVisible(game.k, 0);
}

the_game remake_game(the_game game)
{
    game.boucle = 0;
    game.m = create_menu(game.m);
    game.game = 1;
    game.i = 1;
    game.tzombie = 100;
    game.z = malloc(sizeof(stc_zombie) * game.tzombie);
    for (int i = 0; i < game.tzombie; i++)
        game.z[i] = zombie(game.z[i]);
    game.j = create_vie(game.j);
    game.scoretext = sfTexture_createFromFile("resource/picture/mn.png", NULL);
    game.sprite = sfSprite_create();
    sfSprite_setTexture(game.sprite, game.scoretext, sfTrue);
    game.curseur = sfSprite_create();
    sfSprite_setTexture(game.curseur, sfTexture_createFromFile(\
        "resource/picture/cursor.png", NULL), sfTrue);
    return (game);
}

void place_replay(the_game game)
{
    make_window(game);
    sfSprite_setPosition(game.m.spr_b1, game.m.position);
    sfRenderWindow_drawSprite(game.k, game.m.spr_b1, NULL);
    sfText_setPosition(game.m.txt, game.m.pos_text);
    sfRenderWindow_drawText(game.k, game.m.txt, NULL);
}

the_game my_replay(the_game game)
{
    if (!game.game) {
        sfText_setString(game.m.txt, my_get_score(game.j.compt));
        sfRenderWindow_setMouseCursorVisible(game.k, 1);
        sfSprite_setTexture(game.m.spr_b1, game.m.text2, sfTrue);
    }
    while (!game.game && sfRenderWindow_isOpen(game.k)) {
        place_replay(game);
        game.game = (sfKeyboard_isKeyPressed(sfKeyEscape)) ? 1 : game.game;
        while (sfMouse_isButtonPressed(sfMouseLeft) &&
        sfMouse_getPositionRenderWindow(game.k).x > game.m.position.x &&
        sfMouse_getPositionRenderWindow(game.k).x < game.m.position.x + 618 &&
        sfMouse_getPositionRenderWindow(game.k).y > game.m.position.y &&
        sfMouse_getPositionRenderWindow(game.k).y < game.m.position.y + 155) {
            game.game = 1;
            game = remake_game(game);
        }
    }
    sfRenderWindow_setMouseCursorVisible(game.k, 0);
    game = my_pause(game);
    return (game);
}
