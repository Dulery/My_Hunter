/*
** EPITECH PROJECT, 2018
** creer
** File description:
** oui
*/

#include "../my.h"

stc_zombie zombie(stc_zombie tzombie)
{
    tzombie.clock = sfClock_create();
    tzombie.mort = 3;
    tzombie.seconds = 0;
    tzombie.compteur = 0;
    tzombie.vies = 1;
    (tzombie.hit).height = 110;
    (tzombie.hit).width = 100;
    (tzombie.hit).top = 0;
    (tzombie.hit).left = 110;
    (tzombie.position).x = -110 - (rand() % 500 + 20);
    (tzombie.position).y = rand() % 325 + 375;
    tzombie.sprite = sfSprite_create();
    tzombie.texture = sfTexture_createFromFile
    ("content/image/tzombie.png", NULL);
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
    return (window);
}

stc_vie create_vie(stc_vie heart)
{
    heart.compt = 0;
    heart.coeurs = 3;
    (heart.rect).top = 65;
    (heart.rect).left = 0;
    (heart.rect).height = 100;
    (heart.rect).width = 62;
    (heart.position).x = 10;
    (heart.position).y = 10;
    heart.sprite = sfSprite_create();
    heart.text = sfTexture_createFromFile("content/image/heart.png", NULL);
    heart.textbase = sfText_create();
    sfText_setFont(heart.textbase,
    sfFont_createFromFile("content/image/pl.ttf"));
    sfText_setColor(heart.textbase, sfWhite);
    sfText_setCharacterSize(heart.textbase, 30);
    heart.fusilsound = sfMusic_createFromFile("content/sound/fusilsound.ogg");
    return (heart);
}

the_game make_game(the_game game)
{
    game.boucle = 0;
    game.game = 1;
    game.i = 1;
    game.tzombie = 100;
    game.m = create_menu(game.m);
    game.z = malloc(sizeof(stc_zombie) * game.tzombie);
    for (int i = 0; i < game.tzombie; i++)
        game.z[i] = zombie
    (game.z[i]);
    game.k = create_window();
    game.j = create_vie(game.j);
    game.scoretext = sfTexture_createFromFile("content/image/mn.png", NULL);
    game.sprite = sfSprite_create();
    sfSprite_setTexture(game.sprite, game.scoretext, sfTrue);
    game.curseur = sfSprite_create();
    sfSprite_setTexture(game.curseur, sfTexture_createFromFile(\
        "content/image/cursor.png", NULL), sfTrue);
    return (game);
}
