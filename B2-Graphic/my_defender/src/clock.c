/*
** EPITECH PROJECT, 2021
** clock
** File description:
** file 1
*/

#include "my_defender.h"

void anim_timer(game_clock_t *clock, my_struct_t *store)
{
    clock->anim_time = sfClock_getElapsedTime(clock->anim_clock);
    if (clock->anim_time.microseconds >= clock->anim_t_ms) {
        for (int i = 0; i <
            (clock->anim_time.microseconds / clock->anim_t_ms); i += 1) {
            game_mob_anim(store);
        }
        sfClock_restart(clock->anim_clock);
    }
}

void cu_time_timer(game_clock_t *clock, my_struct_t *store)
{
    clock->cu_time_time = sfClock_getElapsedTime(clock->cu_time_clock);
    if (clock->cu_time_time.microseconds >= clock->cu_time_t_ms) {
        for (int i = 0; i <
            (clock->cu_time_time.microseconds / clock->cu_time_t_ms); i += 1) {
            update_time_txt(store);
        }
        sfClock_restart(clock->cu_time_clock);
    }
}

void move_timer(game_clock_t *clock, my_struct_t *store)
{
    clock->move_time = sfClock_getElapsedTime(clock->move_clock);
    if (clock->move_time.microseconds >= clock->move_t_ms) {
        for (int i = 0; i <
            (clock->move_time.microseconds / clock->move_t_ms); i += 1) {
            game_mob_move(store);
        }
        sfClock_restart(clock->move_clock);
    }
}

void timer(my_struct_t *store)
{
    if (store->game->mode == MODE_GAME) {
        if (store->game->clock->time_freeze == 0) {
            sfClock_restart(store->game->clock->anim_clock);
            sfClock_restart(store->game->clock->cu_time_clock);
            sfClock_restart(store->game->clock->move_clock);
            store->game->clock->time_freeze = 1;
        }
        anim_timer(store->game->clock, store);
        cu_time_timer(store->game->clock, store);
        move_timer(store->game->clock, store);
    }
    if (store->game->mode == MODE_PAUSE
        && store->game->clock->time_freeze == 1)
        pause_mode(store);
}