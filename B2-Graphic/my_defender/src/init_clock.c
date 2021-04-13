/*
** EPITECH PROJECT, 2021
** init_clock
** File description:
** file 1
*/

#include "my_defender.h"

void init_clock(my_struct_t *store)
{
    store->game->clock = malloc(sizeof(game_clock_t));
    store->game->clock->anim_clock = sfClock_create();
    store->game->clock->anim_t_ms = 100000;
    store->game->clock->cu_time_clock = sfClock_create();
    store->game->clock->cu_time_t_ms = 1000000;
    store->game->clock->move_clock = sfClock_create();
    store->game->clock->move_t_ms = 20000;
    store->game->clock->time_freeze = 0;
}

void destroy_clock(my_struct_t *store)
{
    sfClock_destroy(store->game->clock->anim_clock);
    sfClock_destroy(store->game->clock->cu_time_clock);
    sfClock_destroy(store->game->clock->move_clock);
    free(store->game->clock);
}