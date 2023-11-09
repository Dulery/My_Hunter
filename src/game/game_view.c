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
    sfTexture *gamefield = sfTexture_createFromFile("content/game.png", NULL);
    sfSprite *gamefield_sprite = sfSprite_create();
    sfVector2f gamefield_scale = {1.3, 1.3};

    sfSprite_setTexture(gamefield_sprite, gamefield, sfTrue);
    sfSprite_setScale(gamefield_sprite, gamefield_scale);

    sfTexture *zombie = sfTexture_createFromFile("content/zseul.png", NULL);
    sfSprite *zombie_sprite = sfSprite_create();
    sfVector2f zombie_scale = {2, 2};
    int x = 0;
    int y = 390;
    sfVector2f zombie_pos = {x, y};
    float zombie_speed = 0.5;

    sfSprite_setTexture(zombie_sprite, zombie, sfTrue);
    sfSprite_setScale(zombie_sprite, zombie_scale);
    sfSprite_setPosition(zombie_sprite, zombie_pos);
    
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
            if (event.type == sfEvtMouseButtonPressed) {
                x = -500;
                sfVector2f zombie_pos = {x, y};
                sfSprite_setPosition(zombie_sprite, zombie_pos);
            }
            
        }
        
        x += zombie_speed;
        sfVector2f zombie_pos = {x, y};
        sfSprite_setPosition(zombie_sprite, zombie_pos);

        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_drawSprite(window, gamefield_sprite, NULL);
        sfRenderWindow_drawSprite(window, zombie_sprite, NULL);
        sfRenderWindow_display(window);
    }
}
