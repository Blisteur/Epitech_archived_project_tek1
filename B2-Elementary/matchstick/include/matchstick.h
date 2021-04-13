/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** .h
*/

#ifndef MATCHSTICK
#define MATCHSTICK

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "struct.h"

my_struct_t *init_struct(void);
int destroy_struct(my_struct_t *store);
int error_handler(my_struct_t *store, const int argc
                                    , const char * const * argv);
int create_map(my_struct_t *store);
void matchstick(my_struct_t *store);
void destroy_map(my_struct_t *store);
int verif_inputs(my_struct_t *store, const char *buff, int type);
int calcul_lenght(my_struct_t *store);
void remove_matchstick(my_struct_t *store);
void ai_turn(my_struct_t *store);
int count_matchstick_in_line(const char *str);
int verif_end(my_struct_t *store, int type);
void print_map(my_struct_t *store);

#endif /* !MATCHSTICK */