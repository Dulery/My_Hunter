/*
** EPITECH PROJECT, 2018
** my_struct.c
** File description:
** oui
*/

#include "my.h"

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct the_stcfusil {
    sfClock *clock;
    sfTime time;
    sfTexture *text_exp;
    sfSprite *spr_exp;
    sfVector2f pos_exp;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfIntRect rect;
    float seconds;
    int compt;
} stc_fusil;

typedef struct the_stcz {
    sfClock *clock;
    sfTime time;
    int vies;
    int mort;
    float seconds;
    int compteur;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfIntRect hit;
} stc_zombie;

typedef struct the_coeur {
    int heart;
    int compt;
    sfIntRect rect;
    sfText *txt;
    sfTexture *text;
    sfSprite *sprite;
    sfVector2f position;
    sfMusic* fusilsound;
    sfMusic* music;
} stc_vie;

typedef struct the_menu {
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
} stc_menu;

typedef struct the_game {
    stc_zombie *z;
    sfRenderWindow *k;
    stc_vie j;
    stc_menu m;
    sfTexture *text;
    sfSprite *sprite;
    sfEvent event;
    sfSprite *cursorSpr;
    int loop;
    int i;
    int tzombie;
    int game;
} the_game;

#endif
