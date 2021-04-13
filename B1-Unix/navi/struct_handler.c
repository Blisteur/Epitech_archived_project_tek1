/*
** EPITECH PROJECT, 2020
** struct
** File description:
** file 1
*/

#include "include/navy.h"

my_struct *init_struct(void)
{
    my_struct *store = malloc(sizeof(my_struct));

    creat_map(store);
    store->lock_enemy_pid_ok = 0;
    store->game_stade = 0;
    store->attack_statue = 0;
    store->enemy_attack_let = 0;
    store->enemy_attack_nb = 0;
    return (store);
}

void reinit_struct(my_struct *store)
{
    store->attack_statue = 0;
    store->enemy_attack_let = 0;
    store->enemy_attack_nb = 0;
}

void destroy_struct(my_struct *store)
{
    for (int nb = 0; nb < 17; nb += 1)
        free(store->ally_map[nb]);
    free(store->ally_map);
    for (int nb = 0; nb < 17; nb += 1)
        free(store->enemy_map[nb]);
    free(store->enemy_map);
    free(store);
}

verif_map_struct *init_verif_map(void)
{
    verif_map_struct *verif_m = malloc(sizeof(verif_map_struct));

    verif_m->boat2 = 1;
    verif_m->boat3 = 1;
    verif_m->boat4 = 1;
    verif_m->boat5 = 1;
    verif_m->error = 0;
    verif_m->x_max = 0;
    verif_m->x_min = 0;
    verif_m->y_max = 0;
    verif_m->y_min = 0;
    return (verif_m);
}

void destroy_verif_map(verif_map_struct *verif_m)
{
    free(verif_m);
}