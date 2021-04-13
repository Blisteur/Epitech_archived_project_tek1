/*
** EPITECH PROJECT, 2021
** verif end
** File description:
** file 1
*/

#include "matchstick.h"

int verif_end(my_struct_t *store, int type)
{
    int tmp = 0;

    for (int nb = 1; nb < store->nb_lines + 1; nb += 1) {
        tmp += count_matchstick_in_line(store->map[nb]);
    }
    if (tmp != 0)
        return (0);
    print_map(store);
    if (type == 1) {
        my_printf("I lost... snif... but I'll get you next time!!\n");
        store->nb_return = 1;
    }
    if (type == 2) {
        my_printf("You lost, too bad...\n");
        store->nb_return = 2;
    }
    store->game_loop = 1;
    return (1);
}