/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** lib
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

stc_zombie mort_zombie(stc_zombie tzombie);
the_game remake_game(the_game game);
the_game my_pause(the_game game);
void put_gun(the_game game);
void zombie_place(the_game game);
char *my_get_score(int nb);
the_game my_replay(the_game game);
void my_destroy(the_game game);
char *give_score(void);
void menu(the_game game);
the_game spawn_zombie(the_game game);
void my_score(the_game game);
int my_put_nbr(int nb, int fd);
int my_getnbr(char const *str);
stc_zombie zombie(stc_zombie tzombie);
stc_vie create_vie(stc_vie heart);
obj_gun_t create_gun(obj_gun_t gun);
stc_zombie zombie(stc_zombie tzombie);
stc_menu create_menu(stc_menu menu);
the_game player_heart(the_game game);
stc_zombie des_zombie(stc_zombie old);
the_game my_gun_hand(the_game game);
sfRenderWindow *create_window(void);
the_game make_game(the_game game);
the_game re_game(stc_zombie b, obj_gun_t g, sfRenderWindow *w);
void put_bird(the_game game);
void put_heart(the_game game);
void put_text(the_game game);
void viseur(the_game game);
the_game my_zombie(the_game game);
void make_window(the_game game);
the_game my_gun(the_game game);
int bestmusicofalltime(the_game game);

#endif
