/*
** EPITECH PROJECT, 2020
** struct
** File description:
** file 1
*/

#include <stdlib.h>
#include "include/102architect.h"
#include "include/struct.h"

void init_struct(char **argv, my_struct *store)
{
    store->x = atof(argv[1]);
    store->y = atof(argv[2]);
    store->final_x = 0;
    store->final_y = 0;
    store->tmp_x = 0;
    store->tmp_y = 0;
    store->tmp_d = 0;
    store->tab = malloc(sizeof(float *) * 4);
    store->tab[3] = '\0';
    for (int nb = 0; nb < 3; nb += 1) {
        store->tab[nb] = malloc(sizeof(float) * 4);
        store->tab[nb][3] = '\0';
    }
    store->tmp_tab = malloc(sizeof(float *) * 4);
    store->tmp_tab[3] = '\0';
    for (int nb = 0; nb < 3; nb += 1) {
        store->tmp_tab[nb] = malloc(sizeof(float) * 4);
        store->tmp_tab[nb][3] = '\0';
    }
    store->matrix_tmp = malloc(sizeof(float) * 4);
    store->matrix_tmp[3] = '\0';
    store->matrix_tmp[2] = 1;
    store->lock = 0;
}

void destroy_struct(my_struct *store)
{
    for (int nb = 0; nb < 3; nb += 1)
        free(store->tab[nb]);
    for (int nb = 0; nb < 3; nb += 1)
        free(store->tmp_tab[nb]);
    free(store->matrix_tmp);
    free(store->tmp_tab);
    free(store->tab);
    free(store);
}
