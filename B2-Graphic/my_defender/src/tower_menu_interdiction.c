/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** tower_menu_interdiction.c
*/

#include "my_defender.h"

int is_in_forbidden_zone(select_t *select)
{
    sfIntRect menu[3] = {{1440, 0, 192, 864}, {1384, 310, 96, 240},
    {1152, 0, 384, 96}};
    sfIntRect roads[7] = {{4, 292, 280, 88},
                        {196, 100, 88, 280},
                        {196, 100, 472, 88},
                        {580, 100, 88, 664},
                        {580, 676, 472, 88},
                        {964, 388, 88, 376},
                        {964, 388, 472, 88}};

    for (int a = 0; a != 3; a++) {
        if (sfIntRect_intersects(&select->pos, &menu[a], NULL) == 1)
            return (1);
    }
    for (int b = 0; b != 7; b++) {
        if (sfIntRect_intersects(&select->pos, &roads[b], NULL) == 1)
            return (1);
    }
    return (0);
}

int is_in_playable_area(select_t *select)
{
    sfIntRect zone = {32, 64, 1370, 704};

    if (sfIntRect_intersects(&select->pos, &zone, NULL) == 0)
        return (0);
    return (1);
}

int is_tower_conflicting(select_t *select, list_t **list)
{
    struct list_s *temp = *list;

    while (temp != NULL) {
        if (sfIntRect_intersects(&select->pos, &temp->box, NULL) == 1)
            return (1);
        temp = temp->next;
    }
    return (0);
}

int can_place_tower(select_t *select, tower_t *towers)
{
    if (is_tower_conflicting(select, &towers->list) == 1)
        return (0);
    if (is_in_playable_area(select) == 0)
        return (0);
    if (is_in_forbidden_zone(select) == 1)
        return (0);
    return (1);
}