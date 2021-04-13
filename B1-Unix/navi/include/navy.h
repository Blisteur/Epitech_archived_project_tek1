/*
** EPITECH PROJECT, 2020
** navy
** File description:
** .h
*/

#ifndef NAVY
#define NAVY

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include "my.h"
#include "struct.h"

extern my_struct *store;

int error_handler(int argc, char **argv, my_struct *store);
my_struct *init_struct();
void destroy_struct(my_struct *store);
void reinit_struct(my_struct *store);
verif_map_struct *init_verif_map(void);
void destroy_verif_map(verif_map_struct *verif_m);
void get_user(my_struct *store, int argc, char **argv);
int help(void);
int verif_cord(int fd, my_struct *store);
void make_ally_map(my_struct *store, char **map);
int convert_let(char let);
int set_cord_map(char *buff, verif_map_struct *verif_m, char **map);
void verif_cord_error(char *buff, verif_map_struct *verif_m);
int verif_nb(char nb, int lock);
int verif_let(char lt);
void navy(my_struct *store);
void creat_map(my_struct *store);
void init_user_connection(int nb, siginfo_t *info, void *null);
void print_map(my_struct *store);
void waiting_attack(my_struct *store);
void make_attack(my_struct *store);
void receive_attack(int nb, siginfo_t *info, void *null);
void stop_attack(int nb, siginfo_t *info, void *null);
int verif_end_game(my_struct *store);

#endif /* !NAVY */