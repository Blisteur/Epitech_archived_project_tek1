/*
** EPITECH PROJECT, 2020
** push_swap
** File description:
** .h
*/

#ifndef PUSH_SWAP
#define PUSH_SWAP

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include "my.h"
#include "struct.h"

int error_handler(int argc, char **argv);
int excep_handler(int argc, char **argv);
my_struct *init_struct(void);
void destroy_struct(my_struct *store);
linked_list *add_link(int nb, my_struct *store, linked_list *p, char lst);
void remove_link(my_struct *store, linked_list *p, char lst);
void my_rev_list(my_struct *store, linked_list *list);
void swap(linked_list *list, my_struct *store, char lst);
void push(linked_list *list_x, my_struct *store, char lst);
void rotate_f_to_l(linked_list *list_x, my_struct *store, char lst);
void rotate_l_to_f(linked_list *list_x, my_struct *store, char lst);
void change_last_link(my_struct *store, char lst);

#endif /* !PUSH_SWAP */