/*
** EPITECH PROJECT, 2021
** my_sokoban
** File description:
** .h
*/

#ifndef SOKOBAN
#define SOKOBAN

#include "my.h"
#include "my_struct.h"

#include <ncurses.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/ioctl.h>

my_struct *init_stuct(void);
void destroy_struct(my_struct *store, int output);
void error_handler(my_struct *store, const int argc, const char * const *argv);
void init_map(my_struct *store, int fd, struct stat stat_p);
int create_map(my_struct *store, const char *map_link);
my_obj *add_link(int x, int y, my_struct *store, my_obj *p);
void remove_link(my_struct *store, my_obj *p);
int sokoban(my_struct *store);
void move_player(my_struct *store);
int verif_case_move(my_struct *store, int x, int y, char c);
void reset(my_struct *store);
int is_win(my_struct *store);
void print_map(my_struct *store);

#endif /* !SOKOBAN */