/*
** EPITECH PROJECT, 2021
** linked_list
** File description:
** file 1
*/

#include "my_sokoban.h"

my_obj *add_link(int x, int y, my_struct *store, my_obj *p)
{
    my_obj *list = malloc(sizeof(my_obj));

    list->origin_x = x;
    list->origin_y = y;
    list->x = x;
    list->y = y;
    list->c = 'X';
    list->next = p;
    if (p != NULL)
        p->previous = list;
    else
        store->last_obj = list;
    list->previous = NULL;
    p = list;
    store->nbr_obj += 1;
    return (list);
}

void remove_link(my_struct *store, my_obj *p)
{
    if (p->next != NULL) {
        store->first_obj = p->next;
        store->first_obj->previous = NULL;
    } else {
        store->first_obj = NULL;
        store->last_obj = NULL;
    }
    store->nbr_obj -= 1;
    free(p);
}