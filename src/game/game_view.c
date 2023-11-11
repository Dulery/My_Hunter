/*
** EPITECH PROJECT, 2023
** game_view.c
** File description:
** oui
*/

#include <unistd.h>
#include "../../include/my.h"

void anime_sprite(sfClock* clock, sfSprite* zombie_sprite, sfTexture* zombie, sfTexture* zombie2)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = sfTime_asSeconds(time);

    if (seconds > 0.3) {
        sfSprite_setTexture(zombie_sprite, zombie2, sfTrue);
    } else {
        sfSprite_setTexture(zombie_sprite, zombie, sfTrue);
    }

    if (seconds > 0.6) {
        sfClock_restart(clock);
    }
}


void if_click_point(sfRenderWindow* window, sfEvent event, int* p, sfSprite* zombie_sprite)
{
    sfVector2i mouse = sfMouse_getPosition(window);

    if (event.type == sfEvtMouseButtonPressed) {
        sfFloatRect zombieBounds = sfSprite_getGlobalBounds(zombie_sprite);
    }

    if (*p == 10) {
        sfRenderWindow_close(window);
    }
}

void game_function(sfRenderWindow* window, sfEvent event)
{
    sfVector2i mouse = sfMouse_getPosition(window);
    int p = 0;

    sfFont* font = sfFont_createFromFile("content/police.ttf");

    sfText* scoreText = sfText_create();
    sfText_setFont(scoreText, font);
    sfText_setCharacterSize(scoreText, 75);
    sfText_setPosition(scoreText, (sfVector2f){10, 10});
    sfText_setFillColor(scoreText, sfWhite);

    sfTexture *gamefield = sfTexture_createFromFile("content/mainmenu.png", NULL);
    sfSprite *gamefield_sprite = sfSprite_create();
    sfVector2f gamefield_scale = {1.13, 1.055};

    sfSprite_setTexture(gamefield_sprite, gamefield, sfTrue);
    sfSprite_setScale(gamefield_sprite, gamefield_scale);

    sfTexture *zombie = sfTexture_createFromFile("content/zseul.png", NULL);
    sfTexture *zombie2 = sfTexture_createFromFile("content/z2.png", NULL);
    sfSprite *zombie_sprite = sfSprite_create();
    sfVector2f zombie_scale = {2, 2};
    float x = -500.0f;
    int y = 500;
    sfVector2f zombie_pos = {x, y};
    
    sfSprite_setTexture(zombie_sprite, zombie, sfTrue);
    sfSprite_setScale(zombie_sprite, zombie_scale);
    sfSprite_setPosition(zombie_sprite, zombie_pos);

    sfClock* clock = sfClock_create();

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
            if (sfMouse_isButtonPressed(sfMouseLeft)) {
                sfVector2i mouse = sfMouse_getPosition(window);
                sfFloatRect zombieBounds = sfSprite_getGlobalBounds(zombie_sprite);
                if_click_point(window, event, &p, zombie_sprite);

                if (sfFloatRect_contains(&zombieBounds, mouse.x, mouse.y)) {
                    p++;
                    y = rand() % 275 + 300;
                    sfSprite_setPosition(zombie_sprite, (sfVector2f){-150.0f, (float)y});
                    x = -150.0f;
                    sfSprite_setPosition(zombie_sprite, (sfVector2f){x, (float)y});
                }
            }
        }
        anime_sprite(clock, zombie_sprite, zombie, zombie2);
        
        if (y < 0) {
            y = 0;
        } else if (y > 600 - 70) {
            y = 600 - 70;
        }
        sfSprite_setPosition(zombie_sprite, (sfVector2f){x, (float)y});

        x += 0.3f;
        sfSprite_setPosition(zombie_sprite, (sfVector2f){x, (float)y});

        char scoreString[10];
        sprintf(scoreString, "Score: %d", p);
        sfText_setString(scoreText, scoreString);

        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_drawSprite(window, gamefield_sprite, NULL);
        sfRenderWindow_drawSprite(window, zombie_sprite, NULL);
        sfRenderWindow_drawText(window, scoreText, NULL);
        sfRenderWindow_display(window);
    }
    sfText_destroy(scoreText);
    sfFont_destroy(font);
    sfSprite_destroy(gamefield_sprite);
    sfSprite_destroy(zombie_sprite);
    sfTexture_destroy(gamefield);
    sfTexture_destroy(zombie);
    sfTexture_destroy(zombie2);
    sfClock_destroy(clock);
}
