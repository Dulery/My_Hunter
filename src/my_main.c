/*
** EPITECH PROJECT, 2023
** my_main.c
** File description:
** oui
*/

#include <unistd.h>
#include "../include/my.h"

//Fonction click
void if_click(sfRenderWindow* window, sfEvent event)
{
    sfVector2i mouse = sfMouse_getPosition(window);

    if (mouse.x >= 471 && mouse.x <= 807) {
        if (mouse.y >= 486 && mouse.y <= 581) {
            if (event.type == sfEvtMouseButtonPressed)
                game_function(window, event);
        }
    }
}

int main(void)
{
    sfVideoMode mode = {1280, 720, 32};
    sfRenderWindow* window;
    sfEvent event;

    //Def sprites
    sfTexture *texture = sfTexture_createFromFile("content/game.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfTexture *texture02 = sfTexture_createFromFile("content/startbutton.png", NULL);
    sfSprite *button = sfSprite_create();

    sfTexture *titre = sfTexture_createFromFile("content/Zombie.png", NULL);
    sfSprite *sprite_titre = sfSprite_create();

    //Taille sprite
    sfVector2f scale = {1.3, 1.3};
    sfVector2f scale_button = {12, 12};
    sfVector2f scale_titre = {9, 9};

    //Position sprite
    sfVector2f pos_button = {225, 50};
    sfVector2f pos_titre = {400, 6};

    //Affichage image de fond
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);

    //Affichage bouton
    sfSprite_setTexture(button, texture02, sfTrue);
    sfSprite_setScale(button, scale_button);
    sfSprite_setPosition(button, pos_button);

    //Affichage Titre
    sfSprite_setTexture(sprite_titre, titre, sfTrue);
    sfSprite_setScale(sprite_titre, scale_titre);
    sfSprite_setPosition(sprite_titre, pos_titre);

    window = sfRenderWindow_create(mode, "My Hunter", sfTitlebar | sfClose, NULL);

    //Ouverture page avec sprites
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
        }
        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_drawSprite(window, sprite_titre, NULL);
        sfRenderWindow_drawSprite(window, button, NULL);
        sfRenderWindow_display(window);

        if_click(window, event);
    }
    return 0;
}
