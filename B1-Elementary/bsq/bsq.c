/*
** EPITECH PROJECT, 2020
** bsq
** File description:
** file 1
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"
#include "include/struct.h"
#include "include/bsq.h"

void convert_bsq(my_struct *store)
{
    int x = 0;
    int y = store->nb_line;
    int count = 0;

    for (x = 0; store->buff[x] != '\n'; x += 1);
    store->tab = malloc(sizeof(int *) * (x + 1));
    store->tab[x] = '\0';
    for (int nb = 0; nb < x; nb += 1) {
        store->tab[nb] = malloc(sizeof(int) * (y + 1));
        store->tab[nb][y] = '\0';
    }
    store->x = x;
    store->y = y;
    for (int nb_y = 0; nb_y < y; nb_y += 1) {
        for (int nb_x = 0; nb_x < x; nb_x += 1, count += 1) {
            store->tab[nb_x][nb_y] = store->buff[count];
        }
        count += 1;
    }
}

void plus_min_bsq(int nb_y, int nb_x, int **tab, my_struct *store)
{
    int left = tab[nb_x - 1][nb_y];
    int top_left = tab[nb_x - 1][nb_y - 1];
    int top = tab[nb_x][nb_y - 1];
    int res = 0;

    res = (left <= top_left && left <= top) ? left : res;
    res = (top_left <= left && top_left <= top) ? top_left : res;
    res = (top <= top_left && top <= left) ? top : res;
    tab[nb_x][nb_y] = res + 1;
    if ((res + 1) > store->max) {
        store->max = res + 1;
        store->max_x = nb_x;
        store->max_y = nb_y;
    }
}

void make_square(my_struct *store)
{
    int max_x = store->max_x;
    int max_y = store->max_y;
    int min_x = store->max_x - store->max;
    int min_y = store->max_y - store->max;

    for (int nb_y = max_y; nb_y > min_y; nb_y -= 1) {
        for (int nb_x = max_x; nb_x > min_x; nb_x -= 1) {
            store->tab[nb_x][nb_y] = 'x';
        }
    }
    for (int nb_y = 0; nb_y < store->y; nb_y += 1) {
        for (int nb_x = 0; nb_x < store->x; nb_x += 1) {
            if (store->tab[nb_x][nb_y] != 120 && store->tab[nb_x][nb_y] != 0)
                store->tab[nb_x][nb_y] = '.';
            if (store->tab[nb_x][nb_y] == 0)
                store->tab[nb_x][nb_y] = 'o';
        }
    }
    print_bsq(store);
}

void bsq(my_struct *store)
{
    convert_bsq(store);
    for (int nb_y = 0; nb_y < store->y; nb_y += 1) {
        for (int nb_x = 0; nb_x < store->x; nb_x += 1) {
            if (store->tab[nb_x][nb_y] == 'o')
                store->tab[nb_x][nb_y] = 0;
            if (store->tab[nb_x][nb_y] == '.')
                store->tab[nb_x][nb_y] = 1;
        }
    }
    if (store->nb_line == 1 || store->x == 1) {
        verif_execp(store);
        return;
    }
    for (int nb_y = 1; nb_y < store->y; nb_y += 1) {
        for (int nb_x = 1; nb_x < store->x; nb_x += 1) {
            if (store->tab[nb_x][nb_y] == 1)
                plus_min_bsq(nb_y, nb_x, store->tab, store);
        }
    }
    make_square(store);
}

int main(int argc, char **argv)
{
    struct stat info;
    my_struct *store;

    store = malloc(sizeof(my_struct));
    init_struct(store);
    if (error_management(argc, argv, store, info) == 1) {
        free(store->buff);
        free(store);
        return (error_code);
    }
    bsq(store);
    delete_struct(store);
    free(store);
    return (0);
}