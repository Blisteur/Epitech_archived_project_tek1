/*
** EPITECH PROJECT, 2020
** game
** File description:
** .h
*/

#ifndef MY_GAME
#define MY_GAME

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <time.h>
#include "my.h"
#include "struct.h"

#define HELP_MSG_SIZE (764)
#define N_GAME ("MyRunner")

int error_hendler(int argc, char **argv);
int help(void);
void game(char *map_link);
void init_game(my_game *store, char *map_link);
void destroy_game(my_game *store);
void make_map(my_game *store, char *map_link);
void get_settings(my_game *store);
menu_t *make_menu(menu_t *menu);
void destroy_menu(my_game *store);
void create_parallax(my_game *store);
void destroy_parallax(my_game *store);
int menu_boutton_scan(sfVector2i highlight, my_game *store);
void menu_boutton_touch(my_game *store);
void drawsprite(my_game *store);
void events_per_mode(my_game *store);
void move_sprite(my_game *store);
void timer(my_game *store);
void init_clock(my_game *store);
void destroy_clock(my_game *store);
void init_score(my_game *store);
void destroy_score(my_game *store);
mob_t *add_link_mob(my_game *store, mob_t *p, enum mob_type nb);
void remove_link_mob(my_game *store, mob_t *p);
void create_player(my_game *store);
void destroy_player(my_game *store);
void rect_mob_move(mob_t *tmp, sfIntRect *rect);
void rect_player_move(player_t *player, sfIntRect *rect);
void jump_player(my_game *store);
int random_height_jump(void);
void jump_player_statue(my_game *store);
void score_actu(my_game *store, int mode);
void make_high_score(my_game *store);
void make_pause(my_game *store);
void pause_event(my_game *store);
void init_music(my_game *store);
void destroy_music(my_game *store);
void score_music(my_game *store);
void make_mob(my_game *store);
mob_type random_mob(int nb);
void make_mob_with_map(my_game *store);
int random_height_bird(int nb);
int random_mob_spawn(int nb);
void verif_hit_box(my_game *store);
void init_game_over(my_game *store);
void destroy_game_over(my_game *store);
void game_over(my_game *store);
void game_over_event(my_game *store);
void remake_map(my_game *store);
void verif_win(my_game *store);
int verif_file(void);

#endif /* !MY_GAME */