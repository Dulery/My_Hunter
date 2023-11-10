/*
** EPITECH PROJECT, 2023
** game_view.c
** File description:
** oui
*/

#include <unistd.h>
#include "../../include/my.h"

void game_function(sfRenderWindow* window, sfEvent event)
{
    sfVector2i mouse = sfMouse_getPosition(window);

    sfTexture *gamefield = sfTexture_createFromFile("content/game.png", NULL);
    sfSprite *gamefield_sprite = sfSprite_create();
    sfVector2f gamefield_scale = {1.3, 1.3};

    sfSprite_setTexture(gamefield_sprite, gamefield, sfTrue);
    sfSprite_setScale(gamefield_sprite, gamefield_scale);

    sfTexture *zombie = sfTexture_createFromFile("content/zseul.png", NULL);
    sfSprite *zombie_sprite = sfSprite_create();
    sfVector2f zombie_scale = {2, 2};
    float x = -500.0f;
    int y = 500;
    sfVector2f zombie_pos = {x, y};

    sfSprite_setTexture(zombie_sprite, zombie, sfTrue);
    sfSprite_setScale(zombie_sprite, zombie_scale);
    sfSprite_setPosition(zombie_sprite, zombie_pos);
    
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
            if (sfMouse_isButtonPressed(sfMouseLeft)) {
                sfVector2i mouse = sfMouse_getPosition(window);
                sfFloatRect zombieBounds = sfSprite_getGlobalBounds(zombie_sprite);

                if (sfFloatRect_contains(&zombieBounds, mouse.x, mouse.y)) {
                    x = -150.0f;
                    sfSprite_setPosition(zombie_sprite, (sfVector2f){x, (float)y});
                }
            }
        }
        x += 0.1f;
        sfSprite_setPosition(zombie_sprite, (sfVector2f){x, (float)y});

        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_drawSprite(window, gamefield_sprite, NULL);
        sfRenderWindow_drawSprite(window, zombie_sprite, NULL);
        sfRenderWindow_display(window);
    }
}
