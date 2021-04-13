/*
** EPITECH PROJECT, 2020
** manage struct
** File description:
** file 1
*/

#include <stdlib.h>
#include "include/my.h"
#include "include/struct.h"
#include "include/bsq.h"

void init_struct(my_struct *store)
{
    store->nb_line = 0;
    store->x = 0;
    store->y = 0;
    store->max = 0;
    store->max_x = 0;
    store->max_y = 0;
}

void delete_struct(my_struct *store)
{
    for (int nb = 0; nb < store->x; nb += 1) {
        free(store->tab[nb]);
    }
    free(store->buff);
    free(store->tab);
}