/*
** EPITECH PROJECT, 2021
** verif_win
** File description:
** file 1
*/

#include "my_sokoban.h"

int verif_win(my_struct *store)
{
    my_obj *tmp = store->first_obj->next;
    int nb_ok = 0;

    for (int nb = 1; nb < store->nbr_obj; nb += 1) {
        if (store->ddmap[tmp->y][tmp->x] == 'O')
            nb_ok += 1;
        tmp = tmp->next;
    }
    if (nb_ok == (store->nbr_obj - 1))
        return (1);
    return (0);
}

int verif_case(my_struct *store, int x, int y)
{
    my_obj *tmp = store->first_obj->next;

    for (int nb = 1; nb < store->nbr_obj; nb += 1) {
        if (tmp->x == x && tmp->y == y)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

int verif_lose(my_struct *store)
{
    my_obj *tmp = store->first_obj->next;
    int nb_ok = 0;

    for (int nb = 1; nb < store->nbr_obj; nb += 1) {
        if ((store->ddmap[tmp->y][tmp->x - 1] == '#'
        || store->ddmap[tmp->y][tmp->x + 1] == '#'
        || verif_case(store, (tmp->x - 1), tmp->y)
        || verif_case(store, (tmp->x + 1), tmp->y))
        && (store->ddmap[tmp->y - 1][tmp->x] == '#'
        || store->ddmap[tmp->y + 1][tmp->x] == '#'
        || verif_case(store, tmp->x, (tmp->y - 1))
        || verif_case(store, tmp->x, (tmp->y + 1))))
            nb_ok += 1;
        tmp = tmp->next;
    }
    if (nb_ok == (store->nbr_obj - 1))
        return (1);
    return (0);
}

int is_win(my_struct *store)
{
    int wincode = 0;

    wincode = verif_win(store);
    if (wincode == 1) {
        store->loop_stop += 1;
        print_map(store);
        refresh();
        return (0);
    }
    wincode = verif_lose(store);
    if (wincode == 1) {
        store->loop_stop += 1;
        print_map(store);
        refresh();
        return (1);
    }
    return (-1);
}