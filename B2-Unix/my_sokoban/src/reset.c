/*
** EPITECH PROJECT, 2021
** reset
** File description:
** file 1
*/

#include "my_sokoban.h"

void reset(my_struct *store)
{
    my_obj *tmp = store->first_obj;

    for (int nb = 0; nb < store->nbr_obj; nb += 1) {
        tmp->x = tmp->origin_x;
        tmp->y = tmp->origin_y;
        tmp = tmp->next;
    }
}