/*
** EPITECH PROJECT, 2020
** struct
** File description:
** .h
*/

#ifndef MY_STRUCT
#define MY_STRUCT

typedef struct linked_list
{
    int number;
    struct linked_list *next;
    struct linked_list *previous;
}linked_list;

typedef struct my_struct
{
    int count_pushswap;
    int nb_link_list_a;
    int nb_link_list_b;
    linked_list *list_a_first;
    linked_list *list_a_last;
    linked_list *list_b_first;
    linked_list *list_b_last;
}my_struct;

#endif /* !MY_STRUCT */