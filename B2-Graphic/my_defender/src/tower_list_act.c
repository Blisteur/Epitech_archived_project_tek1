/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** tower_list_act.c
*/

#include "my_defender.h"

void tower_has_power(my_struct_t *store, list_t *tower)
{
    sfIntRect powered = {16 * tower->type, 0, 16, 32};

    if (tower->type == 7) {
        powered.left = 0;
        powered.width = 32;
    }
    if (tower->power == 1 || store->game->towers->all == 1) {
        sfSprite_setTextureRect(tower->sprite, powered);
        tower->power = 1;
    }
    else {
        powered.top = 32;
        sfSprite_setTextureRect(tower->sprite, powered);
    }
    return;
}

void tower_act(my_struct_t *store, list_t **list, tower_t *towers)
{
    struct list_s *temp = *list;
    sfTime time = sfClock_getElapsedTime(towers->clock);
    towers->elapsed = time.microseconds / 1000;

    verif_mob_speed(store);
    while (temp != NULL) {
        tower_has_power(store, temp);
        if (temp->cd < towers->elapsed)
            towers->ptr[temp->type](store, temp, towers);
        temp = temp->next;
    }
}

void power_all(my_struct_t *store, list_t *tower, tower_t *towers)
{
    tower->cd = towers->elapsed + 60000;
    store->game->towers->all = 1;
}

int in_range(sfVector2f center, int radius, sfVector2f target)
{
    int x;
    int y;
    int rad;

    x = (target.x - center.x);
    x = x * x;
    y = (target.y - center.y);
    y = y * y;
    rad = radius * radius;
    if (x + y <= rad)
        return (1);
    return (0);
}