/*
** EPITECH PROJECT, 2020
** clock
** File description:
** file 1
*/

#include "include/game.h"

void timer_anim(my_game *store)
{
    store->timer->time_anim = sfClock_getElapsedTime(store->timer->clock_anim);
    if (store->timer->time_anim.microseconds >= 100000) {
        for (int i = 0; i <
            (store->timer->time_anim.microseconds / 100000); i += 1) {
            rect_move(store, &store->rect->rect1, &store->rect->rect2);
        }
        sfClock_restart(store->timer->clock_anim);
    }
}

void timer_move(my_game *store)
{
    store->timer->time_move = sfClock_getElapsedTime(store->timer->clock_move);
    if (store->timer->time_move.microseconds >= store->timer->t_in_ms) {
        for (int i = 0; i <
            (store->timer->time_move.microseconds /
            store->timer->t_in_ms); i += 1) {
            move_sprite(store);
        }
        sfClock_restart(store->timer->clock_move);
    }
}

void timer(my_game *store)
{
    timer_anim(store);
    timer_move(store);
}