/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** oui
*/

#ifndef MY_H_
    #define MY_H_

    #include <SFML/Audio.h>
    #include <stdbool.h>
    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/System/Clock.h>
    #include "struct.h"
    #include <stdio.h>

    #define sftexture_createfromfile
    #define sfrenderwindow_create

void game_function(sfRenderWindow* window, sfEvent event);
void handle_events(sfRenderWindow* window, sfEvent event, sfMusic* music);
sfRenderWindow* init_window(void);
sfMusic* init_music(void);
sfSprite* init_sprite(const char *filePath, sfVector2f scale);
sfSprite* init_button(void);
sfSprite* init_title(void);
void handle_click(sfRenderWindow* window, sfEvent event, sfMusic* music);
#endif
