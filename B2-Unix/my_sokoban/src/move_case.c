/*
** EPITECH PROJECT, 2021
** move_case
** File description:
** file 1
*/

#include "my_sokoban.h"

int case_box(my_struct *store, int x, int y)
{
    my_obj *tmp = store->first_obj->next;

    for (int nb = 1; nb < store->nbr_obj; nb += 1) {
        if (tmp->x == x && tmp->y == y)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

my_obj *verif_case_pose(my_struct *store, int x, int y)
{
    my_obj *tmp = store->first_obj->next;

    for (int nb = 1; nb < store->nbr_obj; nb += 1) {
        if (tmp->x == x && tmp->y == y)
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}

int verif_case_next_pose(my_struct *store, int x, int y, my_obj *tmp)
{
    if (y < store->nb_line_map && y > 0 && x > 0
    && store->ddmap[y][x] != '#' && store->ddmap[y][x] != '\0'
    && store->ddmap[y][x] != '\n' && case_box(store, x, y) == 0) {
        tmp->x = x;
        tmp->y = y;
        return (1);
    }
    return (0);
}

int verif_case_move(my_struct *store, int x, int y, char c)
{
    my_obj *tmp = verif_case_pose(store, x, y);
    int x_or = x;
    int y_or = y;

    if (tmp == NULL)
        return (0);
    if (c == 'd')
        y += 1;
    if (c == 'u')
        y -= 1;
    if (c == 'l')
        x -= 1;
    if (c == 'r')
        x += 1;
    if (verif_case_next_pose(store, x, y, tmp) == 1) {
        store->first_obj->x = x_or;
        store->first_obj->y = y_or;
    }
    return (1);
}