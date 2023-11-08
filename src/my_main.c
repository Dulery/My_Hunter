/*
** EPITECH PROJECT, 2023
** my_main.c
** File description:
** oui
*/

#include <unistd.h>
#include "../include/my.h"

void if_click(sfRenderWindow* window, sfEvent event)
{
    sfVector2i mouse = sfMouse_getPosition(window);

    if (mouse.x >= 471 && mouse.x <= 807) {
        if (mouse.y >= 486 && mouse.y <= 581) {
            if (event.type == sfEvtMouseButtonPressed)
                printf("OUIII\n");
        }
    }
}

int main(void)
{
    sfVideoMode mode = {1280, 720, 32};
    sfRenderWindow* window;
    sfEvent event;
    
    sfTexture *texture = sfTexture_createFromFile("content/main.jpeg", NULL);
    sfSprite *sprite = sfSprite_create();

    sfTexture *texture02 = sfTexture_createFromFile("content/startbutton.png", NULL);
    sfSprite *button = sfSprite_create();

    sfVector2f scale = {1.75, 1.75};
    sfVector2f scale_button = {12, 12};

    sfVector2f pos_button = {225, 50};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);

    sfSprite_setTexture(button, texture02, sfTrue);
    sfSprite_setScale(button, scale_button);
    sfSprite_setPosition(button, pos_button);
    
    window = sfRenderWindow_create(mode, "My Hunter", sfTitlebar | sfClose, NULL);

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
        }
        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_drawSprite(window, button, NULL);
        sfRenderWindow_display(window);

        if_click(window, event);
    }
    return 0;
}
