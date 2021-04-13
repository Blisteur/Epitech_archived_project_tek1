/*
** EPITECH PROJECT, 2020
** print_bsq
** File description:
** file 1
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "include/my.h"
#include "include/struct.h"
#include "include/bsq.h"

void print_bsq(my_struct *store)
{
    int count = 0;

    for (int nb_y = 0; nb_y < store->y; nb_y += 1) {
        for (int nb_x = 0; nb_x < store->x; nb_x += 1, count += 1) {
            store->buff[count] = store->tab[nb_x][nb_y];
        }
        count += 1;
    }
    write(1, store->buff, store->buff_size);
}