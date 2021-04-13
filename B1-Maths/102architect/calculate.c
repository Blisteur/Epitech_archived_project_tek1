/*
** EPITECH PROJECT, 2020
** calculate
** File description:
** file 1
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "include/102architect.h"
#include "include/struct.h"

void calculate_matrix(my_struct *store, int i)
{
    char res_tmp[4][4];
    if (i == 1) {
        store->tab[0][0] = store->tmp_tab[0][0];
        store->tab[1][0] = store->tmp_tab[1][0];
        store->tab[2][0] = store->tmp_tab[2][0];
        store->tab[0][1] = store->tmp_tab[0][1];
        store->tab[1][1] = store->tmp_tab[1][1];
        store->tab[2][1] = store->tmp_tab[2][1];
        store->tab[0][2] = store->tmp_tab[0][2];
        store->tab[1][2] = store->tmp_tab[1][2];
        store->tab[2][2] = store->tmp_tab[2][2];
    }
    if (i == 0) {
        res_tmp[0][0] = (store->tab[0][0] * store->tmp_tab[0][0] + store->tab[1][0] * store->tmp_tab[0][1] + store->tab[2][0] * store->tmp_tab[0][2]);
        res_tmp[1][0] = (store->tab[0][0] * store->tmp_tab[1][0] + store->tab[1][0] * store->tmp_tab[1][1] + store->tab[2][0] * store->tmp_tab[1][2]);
        res_tmp[2][0] = (store->tab[0][0] * store->tmp_tab[2][0] + store->tab[1][0] * store->tmp_tab[2][1] + store->tab[2][0] * store->tmp_tab[2][2]);
        res_tmp[0][1] = (store->tab[0][1] * store->tmp_tab[0][0] + store->tab[1][1] * store->tmp_tab[0][1] + store->tab[2][1] * store->tmp_tab[0][2]);
        res_tmp[1][1] = (store->tab[0][1] * store->tmp_tab[1][0] + store->tab[1][1] * store->tmp_tab[1][1] + store->tab[2][1] * store->tmp_tab[1][2]);
        res_tmp[2][1] = (store->tab[0][1] * store->tmp_tab[2][0] + store->tab[1][1] * store->tmp_tab[2][1] + store->tab[2][1] * store->tmp_tab[2][2]);
        res_tmp[0][2] = (store->tab[0][2] * store->tmp_tab[0][0] + store->tab[1][2] * store->tmp_tab[0][1] + store->tab[2][2] * store->tmp_tab[0][2]);
        res_tmp[1][2] = (store->tab[0][2] * store->tmp_tab[1][0] + store->tab[1][2] * store->tmp_tab[1][1] + store->tab[2][2] * store->tmp_tab[1][2]);
        res_tmp[2][2] = (store->tab[0][2] * store->tmp_tab[2][0] + store->tab[1][2] * store->tmp_tab[2][1] + store->tab[2][2] * store->tmp_tab[2][2]);
        store->tab[0][0] = res_tmp[0][0];
        store->tab[1][0] = res_tmp[1][0];
        store->tab[2][0] = res_tmp[2][0];
        store->tab[0][1] = res_tmp[0][1];
        store->tab[1][1] = res_tmp[1][1];
        store->tab[2][1] = res_tmp[2][1];
        store->tab[0][2] = res_tmp[0][2];
        store->tab[1][2] = res_tmp[1][2];
        store->tab[2][2] = res_tmp[2][2];
    }
    store->lock = 0;
    return;
}

void calculate_translate(my_struct *store, float i, float j)
{
    store->matrix_tmp[0] = store->final_x;
    store->matrix_tmp[1] = store->final_y;
    store->matrix_tmp[2] = 1;
    store->tmp_tab[0][0] = 1;
    store->tmp_tab[1][0] = 0;
    store->tmp_tab[2][0] = i;
    store->tmp_tab[0][1] = 0;
    store->tmp_tab[1][1] = 1;
    store->tmp_tab[2][1] = j;
    store->tmp_tab[0][2] = 0;
    store->tmp_tab[1][2] = 0;
    store->tmp_tab[2][2] = 1;
    store->final_x = (store->tmp_tab[0][0] * store->matrix_tmp[0] + store->tmp_tab[1][0] * store->matrix_tmp[1] + store->tmp_tab[2][0] * store->matrix_tmp[2]);
    store->final_y = (store->tmp_tab[0][1] * store->matrix_tmp[0] + store->tmp_tab[1][1] * store->matrix_tmp[1] + store->tmp_tab[2][1] * store->matrix_tmp[2]);
    store->lock = 1;
    printf("Translation along vector (%.0f, %.0f)\n", i, j);
    return;
}

void calculate_scale(my_struct *store, float m, float n)
{
    store->matrix_tmp[0] = store->final_x;
    store->matrix_tmp[1] = store->final_y;
    store->matrix_tmp[2] = 1;
    store->tmp_tab[0][0] = m;
    store->tmp_tab[1][0] = 0;
    store->tmp_tab[2][0] = 0;
    store->tmp_tab[0][1] = 0;
    store->tmp_tab[1][1] = n;
    store->tmp_tab[2][1] = 0;
    store->tmp_tab[0][2] = 0;
    store->tmp_tab[1][2] = 0;
    store->tmp_tab[2][2] = 1;
    store->final_x = (store->tmp_tab[0][0] * store->matrix_tmp[0] + store->tmp_tab[1][0] * store->matrix_tmp[1] + store->tmp_tab[2][0] * store->matrix_tmp[2]);
    store->final_y = (store->tmp_tab[0][1] * store->matrix_tmp[0] + store->tmp_tab[1][1] * store->matrix_tmp[1] + store->tmp_tab[2][1] * store->matrix_tmp[2]);
    store->lock = 1;
    printf("Scaling by factors %.0f and %.0F\n", m, n);
    return;
}

void calculate_rotation(my_struct *store, float d)
{
    return;
}

void calculate_reflection(my_struct *store, float d)
{
    return;
}