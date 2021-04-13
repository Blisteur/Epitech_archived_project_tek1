/*
** EPITECH PROJECT, 2020
** game
** File description:
** .h
*/

#ifndef GAME
#define GAME

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "struct.h"
#include "my.h"

#define defaut_width (1920)
#define defaut_height (1080)
#define defaut_bitsPerPixel (32)
#define N_GAME ("MyHunter")
#define help_msg_size (441)

void rect_init(my_game *store);
void rect_move(my_game *store, sfIntRect *rect1, sfIntRect *rect2);
void timer(my_game *store);
sfVector2f random_pose(int nb);
void sprite_touch(my_game *store, int nb);
void set_pose_sprite(my_game *store);
void create_sprite(my_game *store);
void destroy_sprite(my_game *store);
void create_texture(my_game *store);
void destroy_texture(my_game *store);
void drawsprite(my_game *store);
void destroy_game(my_game *store);
void set_sprite_rect(my_game *store);
void verif_score(my_game *store);
void set_texture(my_game *store);
void set_texture_rect(my_game *store);
void move_sprite(my_game *store);
void hit_box_mob_type_1(my_game *store, int x, int y);
void hit_box_mob_type_2(my_game *store, int x, int y);
void hit_box_mob_type_3(my_game *store, int x, int y);
void hit_box_mob_type_4(my_game *store, int x, int y);
void sprite_out_mob_1(my_game *store, sfVector2f max);
void sprite_out_mob_2(my_game *store, sfVector2f max);
void sprite_out_mob_3(my_game *store, sfVector2f max);
void sprite_out_mob_4(my_game *store, sfVector2f max);
void create_texture_and_sprite(my_game *store);
void verif_life(my_game *store);
void set_life_texture(my_game *store);
void set_life_sprite(my_game *store);
void destroy_life(my_game *store);
void new_score(my_game *store);
unsigned int verif_high_score(void);

#endif /* !GAME */