/*
** EPITECH PROJECT, 2018
** my_struct.c
** File description:
** oui
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System/Vector2.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct obj_bird_s {
    sfClock *clock;
    sfTime time;
    float seconds;
    int compt;
    int heart;
    int death;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfIntRect rect;
} stc_zombie;

typedef struct obj_gun_s {
    sfClock *clock;
    sfTime time;
    float seconds;
    int compt;
    sfTexture *text_exp;
    sfSprite *spr_exp;
    sfVector2f pos_exp;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfIntRect rect;
} obj_gun_t;

typedef struct obj_heart_s {
    int heart;
    int compt;
    sfIntRect rect;
    sfText *txt;
    sfTexture *text;
    sfSprite *sprite;
    sfVector2f position;
    sfMusic* gun1;
} stc_vie;

typedef struct obj_menu_s {
    sfText *txt;
    char *score;
    sfTexture *text;
    sfTexture *text2;
    sfTexture *text3;
    sfSprite *spr_b1;
    sfSprite *spr_logo;
    sfVector2f position;
    sfVector2f pos_text;
    sfVector2f pos_logo;

} obj_menu_t;

typedef struct game_s {
    stc_zombie *b;
    sfRenderWindow *w;
    stc_vie h;
    obj_menu_t m;
    sfTexture *text;
    sfSprite *sprite;
    sfEvent event;
    sfSprite *cursorSpr;
    int loop;
    int i;
    int bird;
    int game;
} the_game;

#endif
