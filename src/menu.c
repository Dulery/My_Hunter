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
    menu.text = sfTexture_createFromFile("content/image/play.png", NULL);
    menu.text2 = sfTexture_createFromFile("content/image/replay.png", NULL);
    menu.text3 = sfTexture_createFromFile("content/image/logo.png", NULL);
    menu.txt = sfText_create();
    sfText_setFont(menu.txt, sfFont_createFromFile("content/image/pl.ttf"));
    sfText_setCharacterSize(menu.txt, 100);
    sfSprite_setScale(menu.spr_logo, menuspr_logo_scale);
    sfSprite_setTexture(menu.spr_b1, menu.text, sfTrue);
    sfSprite_setTexture(menu.spr_logo, menu.text3, sfTrue);
    sfSprite_setPosition(menu.spr_logo, menu.pos_logo);
    return (menu);
}

void menu(the_game the_game)
{
    int loop = 1;

    while (loop && sfRenderWindow_isOpen(the_game.k)) {
        make_window(the_game);
        sfSprite_setTexture(the_game.m.spr_b1, the_game.m.text, sfTrue);
        sfSprite_setPosition(the_game.m.spr_b1, the_game.m.position);
        sfRenderWindow_drawSprite(the_game.k, the_game.m.spr_b1, NULL);
        sfRenderWindow_drawSprite(the_game.k, the_game.m.spr_logo, NULL);
        sfText_setString(the_game.m.txt, the_game.m.score);
        sfText_setPosition(the_game.m.txt, the_game.m.pos_text);
        sfRenderWindow_drawText(the_game.k, the_game.m.txt, NULL);
        loop = (sfKeyboard_isKeyPressed(sfKeyEscape)) ? 0 : loop;
        while (sfMouse_isButtonPressed(sfMouseLeft) &&
        sfMouse_getPositionRenderWindow(the_game.k).x > 370 &&
        sfMouse_getPositionRenderWindow(the_game.k).x < 988 &&
        sfMouse_getPositionRenderWindow(the_game.k).y > 400 &&
        sfMouse_getPositionRenderWindow(the_game.k).y < 555)
            loop = 0;
    }
    sfRenderWindow_setMouseCursorVisible(the_game.k, 0);
}

void make_res(the_game the_game)
{
    make_window(the_game);
    sfSprite_setPosition(the_game.m.spr_b1, the_game.m.position);
    sfRenderWindow_drawSprite(the_game.k, the_game.m.spr_b1, NULL);
    sfText_setPosition(the_game.m.txt, the_game.m.pos_text);
    sfRenderWindow_drawText(the_game.k, the_game.m.txt, NULL);
}

the_game restart(the_game the_game)
{
    if (!the_game.jeu) {
        sfText_setString(the_game.m.txt, score(the_game.j.compt));
        sfRenderWindow_setMouseCursorVisible(the_game.k, 1);
        sfSprite_setTexture(the_game.m.spr_b1, the_game.m.text2, sfTrue);
    }
    while (!the_game.jeu && sfRenderWindow_isOpen(the_game.k)) {
        make_res(the_game);
        the_game.jeu = (sfKeyboard_isKeyPressed(sfKeyEscape)) ? 1 : the_game.jeu;
        while (sfMouse_isButtonPressed(sfMouseLeft) &&
        sfMouse_getPositionRenderWindow(the_game.k).x > the_game.m.position.x &&
        sfMouse_getPositionRenderWindow(the_game.k).x < the_game.m.position.x + 618 &&
        sfMouse_getPositionRenderWindow(the_game.k).y > the_game.m.position.y &&
        sfMouse_getPositionRenderWindow(the_game.k).y < the_game.m.position.y + 155) {
            the_game.jeu = 1;
            the_game = reload_game(the_game);
        }
    }
    sfRenderWindow_setMouseCursorVisible(the_game.k, 0);
    the_game = my_pause(the_game);
    return (the_game);
}

the_game reload_game(the_game the_game)
{
    the_game.boucle = 0;
    the_game.m = create_menu(the_game.m);
    the_game.jeu = 1;
    the_game.i = 1;
    the_game.tzombie = 100;
    the_game.z = malloc(sizeof(stc_zombie) * the_game.tzombie);
    for (int i = 0; i < the_game.tzombie; i++)
        the_game.z[i] = zombie(the_game.z[i]);
    the_game.j = create_vie(the_game.j);
    the_game.scoretext = sfTexture_createFromFile("content/image/mn.png", NULL);
    the_game.sprite = sfSprite_create();
    sfSprite_setTexture(the_game.sprite, the_game.scoretext, sfTrue);
    the_game.curseur = sfSprite_create();
    sfSprite_setTexture(the_game.curseur, sfTexture_createFromFile(\
        "content/image/cursor.png", NULL), sfTrue);
    return (the_game);
}
