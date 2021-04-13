/*
** EPITECH PROJECT, 2021
** clock
** File description:
** clock handler
*/

#include "../include/game.h"

void init_clock(my_game *store)
{
    store->timer = malloc(sizeof(timer_st));
    store->timer->clock_anim = sfClock_create();
    store->timer->clock_move = sfClock_create();
    store->timer->clock_jump = sfClock_create();
    store->timer->clock_score = sfClock_create();
    store->timer->t_in_ms = 5000;
    store->timer->gravity = 500;
    store->timer->time_freeze = 0;
}

void destroy_clock(my_game *store)
{
    sfClock_destroy(store->timer->clock_anim);
    sfClock_destroy(store->timer->clock_move);
    sfClock_destroy(store->timer->clock_jump);
    sfClock_destroy(store->timer->clock_score);
    free(store->timer);
}