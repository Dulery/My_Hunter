/*
** EPITECH PROJECT, 2023
** my_main.c
** File description:
** oui
*/

#include <unistd.h>
#include "../include/my.h"

int main(void)
{
    sfRenderWindow* window = init_window();
    sfEvent event;
    sfMusic* music = init_music();
    sfSprite* sprite = init_sprite("content/game.png", (sfVector2f){1.3, 1.3});
    sfSprite* button = init_button();
    sfSprite* title = init_title();

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            my_while(window, event);
            handle_events(window, event, music);
        }
        handle_events(window, event, music);
        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_drawSprite(window, title, NULL);
        sfRenderWindow_drawSprite(window, button, NULL);
        sfRenderWindow_display(window);
        handle_click(window, event, music);
    }
    sfRenderWindow_destroy(window);
    sfMusic_destroy(music);
    sfSprite_destroy(sprite);
    sfSprite_destroy(button);
    sfSprite_destroy(title);
    return 0;
}

void my_while(sfRenderWindow* window, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
}

void handle_events(sfRenderWindow* window, sfEvent event, sfMusic* music)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
    }
}

sfRenderWindow* init_window(void)
{
    sfVideoMode mode = {1280, 720, 32};

    return sfRenderWindow_create(mode, "My Hunter", sfTitlebar |
        sfClose, NULL);
}

sfMusic* init_music(void)
{
    sfMusic* music = sfMusic_createFromFile("content/mainsongluigi.ogg");

    if (!music) {
        exit(EXIT_FAILURE);
    }
    sfMusic_setLoop(music, true);
    sfMusic_play(music);
    return music;
}

sfSprite* init_sprite(const char *filePath, sfVector2f scale)
{
    sfTexture* texture = sfTexture_createFromFile(filePath, NULL);
    sfSprite* sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    return sprite;
}

sfSprite* init_button(void)
{
    sfSprite* button = init_sprite("content/startbutton.png", (sfVector2f){12, 12});
    sfVector2f posButton = {225, 50};

    sfSprite_setPosition(button, posButton);
    return button;
}

sfSprite* init_title(void)
{
    sfSprite* title = init_sprite("content/Zombie.png", (sfVector2f){9, 9});
    sfVector2f posTitle = {400, 6};

    sfSprite_setPosition(title, posTitle);
    return title;
}

void handle_click(sfRenderWindow* window, sfEvent event, sfMusic* music)
{
    sfVector2i mouse = sfMouse_getPosition(window);

    if (mouse.x >= 471 && mouse.x <= 807) {
        if (mouse.y >= 486 && mouse.y <= 581) {
            suite_click(window, event, music);
        }
    }
}

void suite_click(sfRenderWindow* window, sfEvent event, sfMusic* music)
{
    if (event.type == sfEvtMouseButtonPressed) {
        sfMusic_stop(music);
        sfMusic_destroy(music);
        game_function(window, event);
    }
}
