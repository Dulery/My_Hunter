/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** oui
*/

#ifndef MY_H_
    #define MY_H_
    #include <unistd.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <time.h>
    #include "struct.h"

void zombie_place(the_game the_game);
char *score(int nb);
the_game restart(the_game the_game);
void my_destroy(the_game the_game);
char *give_score(void);
stc_zombie mort_zombie(stc_zombie tzombie);
the_game reload_game(the_game the_game);
the_game my_pause(the_game the_game);
void put_gun(the_game the_game);
void menu(the_game the_game);
the_game spawn_zombie(the_game the_game);
void my_score(the_game the_game);
int my_put_nbr(int nb, int fd);
int my_getnbr(char const *str);
stc_zombie zombie(stc_zombie tzombie);
stc_vie create_vie(stc_vie heart);
stc_zombie zombie(stc_zombie tzombie);
stc_menu create_menu(stc_menu menu);
the_game player_heart(the_game the_game);
stc_zombie des_zombie(stc_zombie destr);
the_game my_gun_hand(the_game the_game);
sfRenderWindow *create_window(void);
the_game make_game(the_game the_game);
void put_bird(the_game the_game);
void put_heart(the_game the_game);
void put_text(the_game the_game);
void viseur(the_game the_game);
the_game my_zombie(the_game the_game);
void make_window(the_game the_game);
the_game fusil_fon(the_game the_game);
int bestmusicofalltime(the_game the_game);

#endif
