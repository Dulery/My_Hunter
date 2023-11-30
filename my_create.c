/*
** EPITECH PROJECT, 2018
** creer
** File description:
** oui
*/

#include "my.h"

stc_zombie zombie(stc_zombie tzombie)
{
    tzombie.mort = 3;
    tzombie.clock = sfClock_create();
    tzombie.seconds = 0;
    tzombie.compteur = 0;
    tzombie.vies = 1;
    (tzombie.rect).height = 110;
    (tzombie.rect).width = 100;
    (tzombie.rect).top = 0;
    (tzombie.rect).left = 110;
    (tzombie.position).x = -110 - (rand() % 500 + 20);
    (tzombie.position).y = rand() % 325 + 375;
    tzombie.sprite = sfSprite_create();
    tzombie.texture = sfTexture_createFromFile
    ("resource/picture/tzombie.png", NULL);
    sfSprite_setTexture(tzombie.sprite, tzombie.texture, sfTrue);
    return (tzombie);
}

sfRenderWindow *create_window(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    srand(time(NULL));
    video_mode.width = 1380;
    video_mode.height = 820;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "Hunter", sfClose |
    sfResize, NULL);
    sfRenderWindow_setFramerateLimit(window, 50);
    sfRenderWindow_setIcon(window, 100, 100,
    sfImage_getPixelsPtr(sfImage_createFromFile("resource/picture/icon.png")));
    return (window);
}

stc_vie create_vie(stc_vie heart)
{
    heart.compt = 0;
    heart.heart = 3;
    (heart.rect).height = 18;
    (heart.rect).width = 46;
    (heart.rect).top = 50;
    (heart.rect).left = 0;
    (heart.position).x = 1300;
    (heart.position).y = 20;
    heart.sprite = sfSprite_create();
    heart.text = sfTexture_createFromFile("resource/picture/heart.png", NULL);
    heart.txt = sfText_create();
    sfText_setFont(heart.txt,
        sfFont_createFromFile("resource/picture/sc.ttf"));
    sfText_setColor(heart.txt, sfWhite);
    sfText_setCharacterSize(heart.txt, 30);
    heart.gun1 = sfMusic_createFromFile("resource/song/gun1.ogg");
    return (heart);
}

the_game make_game(the_game game)
{
    game.loop = 0;
    game.m = create_menu(game.m);
    game.game = 1;
    game.i = 1;
    game.tzombie = 100;
    game.z = malloc(sizeof(stc_zombie) * game.tzombie);
    for (int i = 0; i < game.tzombie; i++)
        game.z[i] = zombie
    (game.z[i]);
    game.k = create_window();
    game.j = create_vie(game.j);
    game.text = sfTexture_createFromFile("resource/picture/forest.png", NULL);
    game.sprite = sfSprite_create();
    sfSprite_setTexture(game.sprite, game.text, sfTrue);
    game.cursorSpr = sfSprite_create();
    sfSprite_setTexture(game.cursorSpr, sfTexture_createFromFile(\
        "resource/picture/cursor.png", NULL), sfTrue);
    return (game);
}
