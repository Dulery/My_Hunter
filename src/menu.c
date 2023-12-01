/*
** EPITECH PROJECT, 2018
** allmenu.c
** File description:
** oui
*/

#include "../my.h"

stc_menu create_menu(stc_menu menu)
{
    menu.position.x = 370;
    menu.position.y = 400;
    sfVector2f menuspr_logo_scale = {10, 10};
    menu.pos_text = (sfVector2f){1200, 0};
    menu.pos_logo.x = 350;
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
    return menu;
}

void menu(the_game g)
{
    int boucle = 1;

    while (boucle && sfRenderWindow_isOpen(g.k)) {
        make_window(g);
        sfSprite_setTexture(g.m.spr_b1, g.m.text, sfTrue);
        sfSprite_setPosition(g.m.spr_b1, g.m.position);
        sfRenderWindow_drawSprite(g.k, g.m.spr_b1, NULL);
        sfRenderWindow_drawSprite(g.k, g.m.spr_logo, NULL);
        sfText_setString(g.m.txt, g.m.score);
        sfText_setPosition(g.m.txt, g.m.pos_text);
        sfRenderWindow_drawText(g.k, g.m.txt, NULL);
        boucle = (sfKeyboard_isKeyPressed(sfKeyEscape)) ? 0 : boucle;
        while (sfMouse_isButtonPressed(sfMouseLeft) &&
        sfMouse_getPositionRenderWindow(g.k).x > 370 &&
        sfMouse_getPositionRenderWindow(g.k).x < 988 &&
        sfMouse_getPositionRenderWindow(g.k).y > 400 &&
        sfMouse_getPositionRenderWindow(g.k).y < 555)
            boucle = 0;
    }
    sfRenderWindow_setMouseCursorVisible(g.k, 0);
}

void make_res(the_game g)
{
    make_window(g);
    sfSprite_setPosition(g.m.spr_b1, g.m.position);
    sfRenderWindow_drawSprite(g.k, g.m.spr_b1, NULL);
    sfText_setPosition(g.m.txt, g.m.pos_text);
    sfRenderWindow_drawText(g.k, g.m.txt, NULL);
}

the_game restart(the_game g)
{
    if (!g.jeu) {
        sfText_setString(g.m.txt, score(g.j.compt));
        sfRenderWindow_setMouseCursorVisible(g.k, 1);
        sfSprite_setTexture(g.m.spr_b1, g.m.text2, sfTrue);
    }
    while (!g.jeu && sfRenderWindow_isOpen(g.k)) {
        make_res(g);
        g.jeu = (sfKeyboard_isKeyPressed(sfKeyEscape)) ? 1 : g.jeu;
        while (sfMouse_isButtonPressed(sfMouseLeft) &&
        sfMouse_getPositionRenderWindow(g.k).x > g.m.position.x &&
        sfMouse_getPositionRenderWindow(g.k).x < g.m.position.x + 618 &&
        sfMouse_getPositionRenderWindow(g.k).y > g.m.position.y &&
        sfMouse_getPositionRenderWindow(g.k).y < g.m.position.y + 155) {
            g.jeu = 1;
            g = reload_game(g);
        }
    }
    sfRenderWindow_setMouseCursorVisible(g.k, 0);
    g = my_pause(g);
    return g;
}

the_game reload_game(the_game g)
{
    g.boucle = 0;
    g.m = create_menu(g.m);
    g.jeu = 1;
    g.i = 1;
    g.tzombie = 100;
    g.z = malloc(sizeof(stc_zombie) * g.tzombie);
    for (int i = 0; i < g.tzombie; i++)
        g.z[i] = zombie(g.z[i]);
    g.j = create_vie(g.j);
    g.scoretext = sfTexture_createFromFile("content/image/mn.png", NULL);
    g.sprite = sfSprite_create();
    sfSprite_setTexture(g.sprite, g.scoretext, sfTrue);
    g.curseur = sfSprite_create();
    sfSprite_setTexture(g.curseur, sfTexture_createFromFile(\
        "content/image/cursor.png", NULL), sfTrue);
    return g;
}
